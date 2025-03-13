#include "window.hpp"
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <glfw/render.hpp>
#include <glfw/window.hpp>
#include <ref.hpp>

namespace GLFW
{
    GLRenderCore::~GLRenderCore()
    {
        glfwTerminate(); 
    }

    bool GLRenderCore::InitializeCore()
    {
        if (!glfwInit())
        {
            m_InitializeError = "glfwInit"; 
            return false; 
        }

        return true;
    }

    bool GLRenderCore::MakeContextCurrent(Ref<ZG::Window> window)
    {
        window->MakeContextCurrent();
        // load context-specific functions via GLAD/GLFW
        gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
        return true; 
    }

    void GLRenderCore::SetSwapInterval(int swapInterval)
    {
        glfwSwapInterval(swapInterval);
    }

    Ref<ZG::Window> GLRenderCore::CreateWindow()
    {
        return CreateRef<GLFW::Window>();
    }

    Ref<ZG::Window> GLRenderCore::CreateWindow(int width, int height)
    {
        return CreateRef<GLFW::Window>(width, height); 
    }
};