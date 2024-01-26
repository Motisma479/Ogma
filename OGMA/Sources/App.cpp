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
    //glfwSetFramebufferSizeCallback(static_cast<GLFWwindow*>(window), framebuffer_size_callback);

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

//--TEST_MAIN_MENU-----------------------------------------------------------------
//     ImGuiWindowFlags flags = 0;
//     flags |= ImGuiWindowFlags_NoTitleBar;
//     // flags |= ImGuiWindowFlags_NoDocking;

//     ImGui::Begin("Test",nullptr,flags);
// ImGui::SetCursorPos(ImVec2(100,100));
//     ImGui::Text("Hello, world!");
//     ImGui::End();

//---------------------------------------------------------------------------------

if (ImGui::Begin("Main", nullptr))
{
    ImVec2 windowSize = ImGui::GetWindowSize();
    float width = 0;
    float height = 0;


    //--ADD-CONTENT-BUTTON--------------------------------------------------------

    width = 150;
    height = 30;

	ImGui::SetCursorPos(ImVec2(15,(windowSize.y - 15) - height));
	ImGui::Button("Ajouter du contenu", ImVec2(150,30)); //remove size argument (ImVec2) to auto-resize

    //--SEARCH-MODE-SELECTOR------------------------------------------------------

    width = 97;
    height = 0;//not used

	ImGui::SetCursorPos(ImVec2((windowSize.x/2)-(width/2),59.5));
	ImGui::PushItemWidth(width);
	static int item_current8 = 0;
	const char* items8[] = {"Nom", "Auteurs", "Date", "Emplacement", "Edition", "Description", "Tags"};
	ImGui::Combo("##1", &item_current8, items8, IM_ARRAYSIZE(items8));
	ImGui::PopItemWidth();


    //--SEARCH-AREA---------------------------------------------------------------

    width = 325;
    height = 0;//not used

	ImGui::SetCursorPos(ImVec2((windowSize.x/2)-(width/2),87.5));
	ImGui::PushItemWidth(width); //NOTE: (Push/Pop)ItemWidth is optional
	static char str9[128] = "";
	ImGui::InputText("##2", str9, IM_ARRAYSIZE(str9));
	ImGui::PopItemWidth();

    //--RESULTS-AREA--------------------------------------------------------------

    ImGui::SetCursorPos(ImVec2(0,0));

    // ImGui::SpinInt

    //----------------------------------------------------------------------------

    /*
	ImGui::SetCursorPos(ImVec2(134,161.75));
	ImGui::PushItemWidth(200);
	static int i10 = 123;
	ImGui::InputInt("##", &i10);
	ImGui::PopItemWidth();

	ImGui::SetCursorPos(ImVec2(132,122.5));
	ImGui::PushItemWidth(200);
	static int i111 = 0;
	ImGui::SliderInt("##", &i111, -1, 3);
	ImGui::PopItemWidth();

	ImGui::SetCursorPos(ImVec2(136,93.5));
	ImGui::PushItemWidth(200);
	static int i112 = 50;
	ImGui::DragInt("##", &i112, 1);
	ImGui::PopItemWidth();

	ImGui::SetCursorPos(ImVec2(174,393.5));
	ImGui::PushItemWidth(200);
	static int item_current14 = 0;
	const char *items14[] = {"Never", "Gonna", "Give", "You", "Up"};
	ImGui::Combo("##", &item_current14, items14, IM_ARRAYSIZE(items14));
	ImGui::PopItemWidth();

	ImGui::SetCursorPos(ImVec2(234,271));
	ImGui::PushItemWidth(200);
	static int item_current15 = 0;
	const char *items15[] = {"Never", "Gonna", "Give", "You", "Up"};
	ImGui::ListBox("##", &item_current15, items15, IM_ARRAYSIZE(items15));
	ImGui::PopItemWidth();
    */

}
ImGui::End();

    FrameEnd();
}

bool App::ShouldQuit()
{
    return quit;
}