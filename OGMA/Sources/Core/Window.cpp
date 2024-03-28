#include "Core/Window.hpp"
#include <GLFW/glfw3.h>

namespace OGMA::Core
{
    void Window::Create(const char* name, s32_2 size)
	{
        //--GLFW-INITIALIZATION------------------------------------------
        if (!glfwInit())
            return;

        if (!(handle = glfwCreateWindow(size.x, size.y, name, NULL, NULL)))
        {
            glfwTerminate();
            return;
        }
        glfwMakeContextCurrent(static_cast<GLFWwindow*>(handle));
        glfwSetWindowSizeLimits(static_cast<GLFWwindow*>(handle), 960, 800, GLFW_DONT_CARE, GLFW_DONT_CARE);
        //glfwSetFramebufferSizeCallback(static_cast<GLFWwindow*>(window), framebuffer_size_callback);

        glClearColor(0.1960, 0.2039, 0.2235, 1.0000);
        //glClearColor(1, 1, 1, 1.0000);
	}

    void Window::CleanUp()
    {
        glfwTerminate();
    }

    void Window::StartFrame()
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Window::EndFrame()
    {
        glfwSwapBuffers(static_cast<GLFWwindow*>(handle));
    }

    bool Window::ShouldQuit()
    {
        return glfwWindowShouldClose(static_cast<GLFWwindow*>(handle));
    }

    void Window::SetQuit(bool state)
    {
        glfwSetWindowShouldClose(static_cast<GLFWwindow*>(handle), state);
    }

    void* Window::GetHandle()
    {
        return handle;
    }
}