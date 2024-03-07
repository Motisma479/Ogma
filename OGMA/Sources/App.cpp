#include "App.hpp"

#include<iostream>

#include <IMGUI/imgui.h>
#include <IMGUI/backends/imgui_impl_glfw.h>
#include <IMGUI/backends/imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>

#include <windows.h>

#include <curl/curl.h>

constexpr const char* OGMA_VER = "v1.0";


size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total_size = size * nmemb;
    output->append((char*)contents, total_size);
    return total_size;
}

bool checkLatestRelease(const std::string& repoOwner, const std::string& repoName, const std::string& expectedReleaseName) {
    std::string url = "https://github.com/" + repoOwner + "/" + repoName + "/releases/latest";
    bool result = false;
    //could use GitHub api but didn't understand how it's working so will be set on FIXME 

    curl_global_init(CURL_GLOBAL_DEFAULT);
    CURL* curl = curl_easy_init();
    CURLcode res;

    if (!curl)
    {
        curl_global_cleanup();
        return result;
    }
    
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    // Set up callback to receive the response
    std::string response;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    // Perform the HTTP request
    res = curl_easy_perform(curl);

    // Check for errors
    if (res != CURLE_OK) {
        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        curl_easy_cleanup(curl);
        curl_global_cleanup();
        return false;
    }

    size_t pos = response.find("/Motisma479/Ogma/tree/");
    if (pos != std::string::npos) {
        size_t endPos = response.find_first_of("\"", pos + 22);
        std::string latestReleaseName = response.substr(pos + 22, endPos - pos - 22);

        // Compare the release names
        if (latestReleaseName == expectedReleaseName) {
            std::cout << "Latest release name matches the expected release name." << std::endl;
            result = true;
        }
        else {
            std::cout << "Latest release name does not match the expected release name." << std::endl;
        }
    }
    else {
        std::cerr << "Error: Could not find release name in the response." << std::endl;
    }

    curl_easy_cleanup(curl);

    curl_global_cleanup();
    return result;
}


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

    curl_version_info_data* vinfo = curl_version_info(CURLVERSION_NOW);
    std::cout << "libcurl version: " << vinfo->version << std::endl;

    std::string repoOwner = "Motisma479";
    std::string repoName = "Ogma";

    if (!checkLatestRelease(repoOwner, repoName, OGMA_VER))
    {
        // Do something if the release names match
    }
    
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
    glfwSetWindowSizeLimits(static_cast<GLFWwindow*>(window), 650, 650, GLFW_DONT_CARE, GLFW_DONT_CARE);
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

    //ImGui::ShowDemoWindow();

    // We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
    // because it would be confusing to have two docking targets within each others.
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar;
    
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

    // ImGui::End();

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

    size = {150.f,30.f};
    pos = ImVec2(15,(windowSize.y - 15) - size.y);

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

    //--RESULTS-AREA--------------------------------------------------------------
    ImVec2 rAreaSize = size = {windowSize.x - 100.f, windowSize.y - 320.f};
    ImVec2 rAreaPos = pos = ImVec2(windowPos.x + (windowSize.x/2)-(size.x/2), windowPos.y + 200.f);

    ImGui::GetWindowDrawList()->AddRectFilled(pos,
    ImVec2(pos.x + size.x, pos.y + size.y),
    0xFFd68eaa,
    13.000000,
    0);

    //--RESULTS-RESULT--------------------------------------------------------------
    size = {rAreaSize.x - 20.f, 150.f};

    int showingResult = rAreaSize.y / 160;
    float offsetResult = (rAreaSize.y - (150 * showingResult)) /(showingResult+1) ;//rAreaSize.y - (150.f * showingResult);
    //std::cout << offsetResult << std::endl;

    for (int i = 0; i < showingResult; i++)
    {
        pos = ImVec2(rAreaPos.x + (rAreaSize.x/2)-(size.x/2), rAreaPos.y + offsetResult + (size.y+ offsetResult )*i);

        ImGui::SetCursorPos(ImVec2(0,0));
        ImGui::GetWindowDrawList()->AddRectFilled(pos,
        ImVec2(pos.x + size.x, pos.y + size.y),
        0xFF0000ff,
        13.000000,
        0);
    }

    //--RESULTS-PAGES--------------------------------------------------------------

    size = {50.f, 50.f};
    for(int i = 0; i< 10; i++)
    {
        pos = ImVec2(windowPos.x + (windowSize.x/2)-(size.x/2) -270 + i*60, rAreaSize.y+rAreaPos.y+10);

        ImGui::GetWindowDrawList()->AddRectFilled(pos,
        ImVec2(pos.x + size.x, pos.y + size.y),
        0xFFff0000,
        13.000000,
        0);
    }
    


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
    return quit;
}