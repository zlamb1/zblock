#include "event/window.hpp"
#include "event/kb.hpp"
#include "event/mouse.hpp"
#include "glfw/kb.hpp"
#include "window/kb.hpp"
#include <GLFW/glfw3.h>

#include <glfw/mouse.hpp>
#include <glfw/window.hpp>

#include <window/mouse.hpp>

#define WINDOW_PTR(W) (Window*) glfwGetWindowUserPointer((W))

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
            return;
        }

        glfwSetWindowUserPointer(m_Handle, this);
        glfwSetFramebufferSizeCallback(m_Handle, glfwWindowSize);
        glfwSetMouseButtonCallback(m_Handle, glfwMouseClick);
        glfwSetCursorPosCallback(m_Handle, glfwMouseMove);
        glfwSetWindowFocusCallback(m_Handle, glfwWindowFocus);
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

    bool Window::IsMouseButtonClicked(ZG::MouseButton button)
    {
        int glfwButton = ZG_MOUSE_BTN_TO_GLFW(button); 
        if (glfwButton == -1) return false;
        return glfwGetMouseButton(m_Handle, glfwButton) == GLFW_PRESS; 
    }

    void Window::ShowCursor()
    {
        glfwSetInputMode(m_Handle, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }
    
    void Window::HideCursor()
    {
        glfwSetInputMode(m_Handle, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    }

    ZG::KeyAction Window::GetKeyState(ZG::KeyCode keyCode)
    {
        switch (glfwGetKey(m_Handle, KeyCodeConvertGLFW(keyCode)))
        {
            case GLFW_PRESS:
                return ZG::KeyAction::PRESS;
            default:
                return ZG::KeyAction::RELEASE; 
        }
    }

    bool Window::IsFocused()
    {
        return glfwGetWindowAttrib(m_Handle, GLFW_FOCUSED); 
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

    void Window::glfwWindowSize(GLFWwindow* window, int width, int height)
    {
        auto windowPtr = WINDOW_PTR(window);
        if (windowPtr != nullptr)
        {
            auto windowSizeEvent = CreateRef<ZG::WindowSizeEvent>(windowPtr->GetRef()); 
            windowPtr->DispatchEvent(windowSizeEvent); 
        }
    }

    void Window::glfwWindowFocus(GLFWwindow *window, int focused)
    {
        auto windowPtr = WINDOW_PTR(window);
        if (windowPtr != nullptr)
        {
            auto windowFocusEvent = CreateRef<ZG::WindowFocusEvent>(windowPtr->GetRef()); 
            windowPtr->DispatchEvent(windowFocusEvent); 
        }
    }

    void Window::glfwMouseClick(GLFWwindow *window, int button, int action, int mods)
    {
        auto windowPtr = WINDOW_PTR(window);
        if (windowPtr != nullptr)
        {
            ZG::MouseButton mouseButton = GLFWConvertMouseBtn(button);
            ZG::MouseAction mouseAction;

            switch(action) 
            {
                case GLFW_PRESS:   
                    mouseAction = ZG::MouseAction::PRESS;
                    break;
                default:           
                    mouseAction = ZG::MouseAction::RELEASE;
                    break;
            }

            auto mouseClickEvent = CreateRef<ZG::MouseClickEvent>(windowPtr->GetRef(), mouseAction, mouseButton);
            windowPtr->DispatchEvent(mouseClickEvent);
        }
    }

    void Window::glfwMouseMove(GLFWwindow* window, double x, double y)
    {
        auto windowPtr = WINDOW_PTR(window);
        if (windowPtr != nullptr)
        {
            auto mouseMoveEvent = CreateRef<ZG::MouseMoveEvent>(windowPtr->GetRef()); 
            windowPtr->DispatchEvent(mouseMoveEvent); 
        }
    }

    void Window::glfwKeyPress(GLFWwindow *window, int key, int scancode, int action, int mods)
    {
        auto windowPtr = WINDOW_PTR(window);
        if (windowPtr != nullptr)
        {
            ZG::KeyAction keyAction;
            ZG::KeyCode keyCode;

            switch (action)
            {
                case GLFW_PRESS:
                    keyAction = ZG::KeyAction::PRESS;
                    break;
                case GLFW_REPEAT:
                    keyAction = ZG::KeyAction::REPEAT;
                    break;
                case GLFW_RELEASE:
                    keyAction = ZG::KeyAction::RELEASE;
                    break;
            }

            keyCode = (ZG::KeyCode) GLFWConvertKeyCode(key); 

            auto keyPressEvent = CreateRef<ZG::KeyPressEvent>(windowPtr->GetRef(), keyAction, keyCode); 
            windowPtr->DispatchEvent(keyPressEvent); 
        }
    }
};