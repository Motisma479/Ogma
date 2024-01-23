#include "App.hpp"

#include<iostream>

#include <IMGUI/imgui.h>
#include <IMGUI/backends/imgui_impl_glfw.h>
#include <IMGUI/backends/imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>

#include <windows.h>


void framebuffer_size_callback(GLFWwindow* window, s32 width, s32 height)
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

bool App::Initialize(s32_2 size, const char* title)
{
    std::cout << "App initialization started" << std::endl;
    
    //--GLFW-INITIALIZATION------------------------------------------
    if (!glfwInit())
        return false;

    if (!(window = glfwCreateWindow(size.x, size.y, title, NULL, NULL)))
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



    static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

    // We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
    // because it would be confusing to have two docking targets within each others.
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
    
    const ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->WorkPos);
    ImGui::SetNextWindowSize(viewport->WorkSize);
    ImGui::SetNextWindowViewport(viewport->ID);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
    window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

    ImGui::Begin("DockSpace Demo", NULL, window_flags);
    ImGui::PopStyleVar();

    ImGui::PopStyleVar(2);

    // Submit the DockSpace
    ImGuiIO& io = ImGui::GetIO();
    if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
    {
        ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
    }
    



    
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("Fichier"))
        {
            ImGui::MenuItem("Exporter une sauvegarde");
            ImGui::MenuItem("Importer une sauvegarde");
            ImGui::Separator();
            if(ImGui::MenuItem("Quiter")){quit = true;}

            ImGui::EndMenu();
        }
        //if(ImGui::BeginMenu("Aide")){}
        if(ImGui::MenuItem("Aide"))
        {
            ShellExecute(0, 0, "https://github.com/Motisma479/UFAFAC/wiki", 0, 0, SW_SHOW);
        }

        ImGui::EndMenuBar();
    } 

    ImGui::End();

    FrameEnd();
}

bool App::ShouldQuit()
{
    return quit;
}