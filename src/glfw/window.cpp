#include "GLFW/glfw3.h"
#include <glfw/window.hpp>

namespace GLFW
{
    Window::Window() 
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 

        m_Handle = glfwCreateWindow(100, 100, "", NULL, NULL); 

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

    void Window::SetSize(uint width, uint height)
    {
        glfwSetWindowSize(m_Handle, width, height); 
    }

    void Window::SetTitle(const std::string& title)
    {
        m_Title = title; 
        glfwSetWindowTitle(m_Handle, m_Title.c_str()); 
    }

    uint Window::GetWidth() 
    {
        int w, h;
        glfwGetWindowSize(m_Handle, &w, &h); 
        return w; 
    } 

    uint Window::GetHeight()
    {
        int w, h;
        glfwGetWindowSize(m_Handle, &w, &h); 
        return h; 
    }

    const std::string& Window::GetTitle()
    {
        const char *title = glfwGetWindowTitle(m_Handle);
        m_Title = title; 
        return m_Title; 
    }

    bool Window::IsRunning()
    {
        return !glfwWindowShouldClose(m_Handle);
    }
};