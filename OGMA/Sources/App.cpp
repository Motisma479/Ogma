#include "App.hpp"

#include<iostream>

#include <IMGUI/imgui.h>
#include <IMGUI/backends/imgui_impl_glfw.h>
#include <IMGUI/backends/imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

using namespace OGMA;

App::App() : quit(false)
{
    std::cout << "App created" << std::endl; 
}

App::~App()
{
    glfwTerminate();
}

bool App::Initialize()
{
    std::cout << "App initialization started" << std::endl;
    
    //--GLFW-INITIALIZATION------------------------------------------
    if (!glfwInit())
        return false;

    if (!(window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL)))
    {
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(static_cast<GLFWwindow*>(window));
    glfwSetFramebufferSizeCallback(static_cast<GLFWwindow*>(window), framebuffer_size_callback);

    //--IMGUI-INITIALIZATION-----------------------------------------
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    ImGui::StyleColorsDark();//set the theme
    ImGui_ImplGlfw_InitForOpenGL(static_cast<GLFWwindow*>(window), true);
    ImGui_ImplOpenGL3_Init("#version 130");

    std::cout << "App initialized" << std::endl;
    return true;
}

void App::FrameStart()
{
    glfwPollEvents();
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    glClear(GL_COLOR_BUFFER_BIT);

    quit = glfwWindowShouldClose(static_cast<GLFWwindow*>(window));
}

void App::FrameEnd()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(static_cast<GLFWwindow*>(window));
}

void App::Update()
{
    FrameStart();

    ImGui::ShowDemoWindow();

    FrameEnd();
}

bool App::ShouldQuit()
{
    return quit;
}