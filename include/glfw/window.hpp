#pragma once

#include <GLFW/glfw3.h>

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

            virtual const std::string& GetTitle() override;
            virtual void SetTitle(const std::string& title) override;

            virtual bool IsRunning() override; 

        protected:
            std::string m_Title; 

    };
}