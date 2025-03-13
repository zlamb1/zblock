#include <GLFW/glfw3.h>

#include <glfw/window.hpp>

namespace GLFW
{
    Window::Window() : GLFW::Window(100, 100)
    {
    }

    Window::Window(int width, int height) 
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 

        m_Handle = glfwCreateWindow(width, height, "", NULL, NULL); 

        if (m_Handle == nullptr)
        {
            m_Initialized = false;
            m_InitializeErrorHint = "GLFW Window Failed To Initialize\n"; 
        }
    }

    Window::~Window() 
    {
        glfwDestroyWindow(m_Handle);
    }

    void Window::MakeContextCurrent()
    {
        glfwMakeContextCurrent(m_Handle); 
    }

    void Window::SwapBuffers() 
    {
        glfwSwapBuffers(m_Handle); 
    }

    void Window::PollEvents()
    {
        glfwPollEvents(); 
    }

    int Window::GetX() 
    {
        int x, y;
        glfwGetWindowPos(m_Handle, &x, &y);
        return x; 
    }

    int Window::GetY() 
    {
        int x, y;
        glfwGetWindowPos(m_Handle, &x, &y);
        return y; 
    }

    void Window::SetPosition(int x, int y)
    {
        glfwSetWindowPos(m_Handle, x, y);
    }

    int Window::GetWidth() 
    {
        int w, h;
        glfwGetWindowSize(m_Handle, &w, &h); 
        return w; 
    } 

    int Window::GetHeight()
    {
        int w, h;
        glfwGetWindowSize(m_Handle, &w, &h); 
        return h; 
    }

    void Window::SetSize(int width, int height)
    {
        glfwSetWindowSize(m_Handle, width, height); 
    }

    double Window::GetMouseX()
    {
        double x, y;
        glfwGetCursorPos(m_Handle, &x, &y);
        return x; 
    }

    double Window::GetMouseY()
    {
        double x, y;
        glfwGetCursorPos(m_Handle, &x, &y);
        return y; 
    }

    void Window::SetMousePosition(double x, double y)
    {
        glfwSetCursorPos(m_Handle, x, y);
    }

    const std::string& Window::GetTitle()
    {
        const char *title = glfwGetWindowTitle(m_Handle);
        m_Title = title; 
        return m_Title; 
    }

    void Window::SetTitle(const std::string& title)
    {
        m_Title = title; 
        glfwSetWindowTitle(m_Handle, m_Title.c_str()); 
    }

    bool Window::IsRunning()
    {
        return !glfwWindowShouldClose(m_Handle);
    }
};