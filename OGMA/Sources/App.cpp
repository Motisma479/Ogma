#include "App.hpp"

#include<iostream>

#include <IMGUI/imgui.h>
#include <IMGUI/imgui_internal.h>
#include <IMGUI/backends/imgui_impl_glfw.h>
#include <IMGUI/backends/imgui_impl_opengl3.h>


#include <windows.h>

#include "ReleaseData.hpp"

constexpr const char* OGMA_VER = "v0.0";

using namespace OGMA;

App::App()
{
    std::cout << "App created" << std::endl; 

    ReleaseData version = ReleaseData::GetLatestData("Motisma479", "Ogma", OGMA_VER);

    if (version.status == ReleaseStatus::NEW_VERSION)
    {
        // Do something if the release names match
        std::cout << "A new update is available for Ogma! : " << OGMA_VER << " -> " << ((version.nameReceived != nullptr) ? version.nameReceived : "ERROR") << std::endl;
    }
    
}

App::~App()
{
    window.CleanUp();
}

bool App::Initialize(const char* name, s32_2 size)
{
    std::cout << "App initialization started" << std::endl;
    
    window.Create(name, size);

    //--IMGUI-INITIALIZATION-----------------------------------------
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    ImGui::StyleColorsDark();//set the theme
    ImGui_ImplGlfw_InitForOpenGL(static_cast<GLFWwindow*>(window.GetHandle()), true);
    ImGui_ImplOpenGL3_Init("#version 130");

    std::cout << "App initialized" << std::endl;
    return true;
}

void App::FrameStart()
{
    window.StartFrame();
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void App::FrameEnd()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    window.EndFrame();
}
bool beginFile = false;
void App::Update()
{
    FrameStart();

    //ImGui::ShowDemoWindow();

    // We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
    // because it would be confusing to have two docking targets within each others.
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoTitleBar;

    ImGuiWindowFlags Resultflags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar;
    
    const ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->WorkPos);
    ImGui::SetNextWindowSize(viewport->WorkSize);
    ImGui::SetNextWindowViewport(viewport->ID);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    window_flags |=  ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
    window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

    ImGui::Begin("DockSpace Demo", NULL, window_flags | ImGuiWindowFlags_NoBackground);
    ImGui::PopStyleVar();

    ImGui::PopStyleVar(2);

    // Submit the DockSpace
    
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, { 0,9 });
    ImGui::PushStyleColor(ImGuiCol_MenuBarBg, 0);
    ImGuiWindowFlags wwindow_flags = ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_MenuBar;
    if (ImGui::BeginViewportSideBar("##MainBar", NULL, ImGuiDir_Up, 30, wwindow_flags)) {
        if (ImGui::BeginMenuBar()) {
            if (ImGui::BeginMenu("Fichier"))
            {
                ImGui::MenuItem("Exporter une sauvegarde");
                ImGui::MenuItem("Importer une sauvegarde");
                ImGui::Separator();
                if (ImGui::MenuItem("Quiter")) { window.SetQuit(true); }

                ImGui::EndMenu();
            }
            if (ImGui::Button("fFichier", { 83,30 }))
            {
                ImGui::BeginPopup("ff");

                ImGui::Button("ffeur", { 83,30 });

                ImGui::EndPopup();
            }
            //if(ImGui::BeginMenu("Aide")){}
            /*ImGui::SetNextWindowSize({ 100,0 });
            if (ImGui::MenuItem("Aide"))
            {
                ShellExecute(0, 0, "https://github.com/Motisma479/UFAFAC/wiki", 0, 0, SW_SHOW);
            }*/

            if (ImGui::Button("Aide", { 83,30 }))
            {
                ShellExecute(0, 0, "https://github.com/Motisma479/UFAFAC/wiki", 0, 0, SW_SHOW);
            }

            ImGui::EndMenuBar();
        }
    }
    ImGui::End();
    ImGui::PopStyleColor();
    ImGui::PopStyleVar(1);


    //ImGui::PushStyleVar(ImGuiStyleVar_, 13.0f);
    //ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, { 30,30 });
    //ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, { 30,30 });
    /*
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("Fichier"))
        {
            ImGui::MenuItem("Exporter une sauvegarde");
            ImGui::MenuItem("Importer une sauvegarde");
            ImGui::Separator();
            if(ImGui::MenuItem("Quiter")){window.SetQuit(true);}

            ImGui::EndMenu();
        }
        //if(ImGui::BeginMenu("Aide")){}
        if(ImGui::MenuItem("Aide"))
        {
            ShellExecute(0, 0, "https://github.com/Motisma479/UFAFAC/wiki", 0, 0, SW_SHOW);
        }

        ImGui::EndMenuBar();
    } 
    //ImGui::PopStyleVar(1);
    // ImGui::End();
    */

//--TEST_MAIN_MENU-----------------------------------------------------------------
//     ImGuiWindowFlags flags = 0;
//     flags |= ImGuiWindowFlags_NoTitleBar;
//     // flags |= ImGuiWindowFlags_NoDocking;

//     ImGui::Begin("Test",nullptr,flags);
// ImGui::SetCursorPos(ImVec2(100,100));
//     ImGui::Text("Hello, world!");
//     ImGui::End();

//---------------------------------------------------------------------------------

// if (ImGui::Begin("Main", nullptr))
// {
    ImVec2 windowSize = ImGui::GetWindowSize();
    ImVec2 windowPos = ImGui::GetWindowPos();
    ImVec2 size(0.f, 0.f);
    ImVec2 pos(0.f, 0.f);


    //--ADD-CONTENT-BUTTON--------------------------------------------------------

    size = {250.f,60.f};
    pos = ImVec2(10,(windowSize.y - 10) - size.y);

	ImGui::SetCursorPos(pos);
	ImGui::Button("Ajouter du contenu", size); //remove size argument (ImVec2) to auto-resize

    //--SEARCH-MODE-SELECTOR------------------------------------------------------
    size = {97.f, 0.f};
    pos = ImVec2((windowSize.x/2)-(size.x/2),59.5);

	ImGui::SetCursorPos(pos);
	ImGui::PushItemWidth(size.x);
	static int item_current8 = 0;
	const char* items8[] = {"Nom", "Auteurs", "Date", "Emplacement", "Edition", "Description", "Tags"};
	ImGui::Combo("##1", &item_current8, items8, IM_ARRAYSIZE(items8));
	ImGui::PopItemWidth();


    //--SEARCH-AREA---------------------------------------------------------------
    size = {325.f, 0.f};
    pos = ImVec2((windowSize.x/2)-(size.x/2),87.5);

	ImGui::SetCursorPos(pos);
	ImGui::PushItemWidth(size.x); //NOTE: (Push/Pop)ItemWidth is optional
	static char str9[128] = "";
	ImGui::InputText("##2", str9, IM_ARRAYSIZE(str9));
	ImGui::PopItemWidth();


    size = { 940.f, windowSize.y - 340 };
    //size = { 940.f, 460 };
    pos = ImVec2(windowPos.x + (windowSize.x/2)-(size.x/2), windowPos.y + 240.f);
    ImGui::SetNextWindowPos(pos);
    ImGui::SetNextWindowSize(size);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 13.0f);
    if (ImGui::Begin("Result", 0, Resultflags))
    {
        float scroll = ImGui::GetScrollY();

        //--RESULTS-AREA--------------------------------------------------------------

        //ImGui::GetWindowDrawList()->AddRectFilled(pos,
        //ImVec2(pos.x + size.x, pos.y + size.y),
        //0xFFd68eaa,
        //13.000000,
        //0);



        //--RESULTS-RESULT--------------------------------------------------------------
        size = {800, 120.f};

        int showingResult = 5;//static_cast<int>(rAreaSize.y / 160);
        
        //std::cout << offsetResult << std::endl;

        ImVec2 offset = ImGui::GetWindowPos();
        offset.x += 60;
        offset.y += 30;

        int y = 0;
        for (int i = 0; i < showingResult; [&] {i++; y += 140; }())
        {
        //    //pos = ImVec2(rAreaPos.x + (rAreaSize.x / 2) - (size.x / 2), rAreaPos.y + offsetResult + (size.y + offsetResult) * i);
            pos = ImVec2(offset);
            pos.y += y;

            ImGui::GetWindowDrawList()->AddRectFilled({ pos.x,pos.y - scroll },
            ImVec2(pos.x + size.x, pos.y + size.y - scroll),
            0xFF0000ff,
            13.000000,
            0);

            ImGui::GetWindowDrawList()->AddImageRounded(0,
            { pos.x,pos.y - scroll },
            ImVec2(pos.x + 240, pos.y + 120 - scroll),
            { 0,0 },
            { 1,1 },
            4294967295,
            13.0000f,
            240);

            ImGui::SetCursorPos({0, y + 160.f });
            ImGui::Text(" ");
        }

        ImGui::End();
    }
    ImGui::PopStyleVar(1);

    //--RESULTS-PAGES--------------------------------------------------------------

    /*size = {50.f, 50.f};
    for(int i = 0; i< 10; i++)
    {
        pos = ImVec2(windowPos.x + (windowSize.x/2)-(size.x/2) -270 + i*60, rAreaSize.y+rAreaPos.y+10);

        ImGui::GetWindowDrawList()->AddRectFilled(pos,
        ImVec2(pos.x + size.x, pos.y + size.y),
        0xFFff0000,
        13.000000,
        0);
    }*/
    
    //ImGui::GetWindowDrawList()->AddLine({ 0.f, 0.f }, { 100.f,100.f }, 0xFFFFFFFF, 5);

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

// }
ImGui::End();

    FrameEnd();
}

bool App::ShouldQuit()
{
    return window.ShouldQuit();
}