#pragma once

#include <GLFW/glfw3.h>

#include <glfw/mouse.hpp>
#include <window/window.hpp>

#include <resource.hpp>

namespace GLFW
{
    class Window : public ZG::Window, public ResourceHandle<GLFWwindow*>
    {
        public:
            Window();
            Window(int width, int height); 
            virtual ~Window() override;

            virtual void MakeContextCurrent() override;
            virtual void SwapBuffers() override; 
            virtual void PollEvents() override;

            virtual int GetX() override;
            virtual int GetY() override;
            virtual void SetPosition(int x, int y) override; 

            virtual int GetWidth() override; 
            virtual int GetHeight() override; 

            virtual void SetSize(int width, int height) override; 

            virtual double GetMouseX() override;
            virtual double GetMouseY() override;
            virtual void SetMousePosition(double x, double y) override;

            virtual bool IsMouseButtonClicked(ZG::MouseButton button) override;

            virtual void ShowCursor() override;
            virtual void HideCursor() override; 

            virtual ZG::KeyAction GetKeyState(ZG::KeyCode keyCode) override; 

            virtual bool IsFocused() override; 

            virtual const std::string& GetTitle() override;
            virtual void SetTitle(const std::string& title) override;

            virtual bool IsRunning() override; 

        protected:
            std::string m_Title; 

            static int ZG_MOUSE_BTN_TO_GLFW(ZG::MouseButton button) { ZG_GLFW_MOUSE_BTN_CONV(button) }

        private:
            static void glfwWindowSize(GLFWwindow *window, int width, int height);
            static void glfwWindowFocus(GLFWwindow *window, int focused);
            static void glfwMouseClick(GLFWwindow *window, int button, int action, int mods);
            static void glfwMouseMove(GLFWwindow *window, double x, double y);
            static void glfwKeyPress(GLFWwindow *window, int key, int scancode, int action, int mods); 

    };
}