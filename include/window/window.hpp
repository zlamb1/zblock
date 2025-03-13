#pragma once

#include <string>
#include <types.hpp>

namespace ZG
{
    class Window
    {
        public:
            Window() = default;
            virtual ~Window() = default;

            virtual void MakeContextCurrent() = 0; 
            virtual void SwapBuffers() = 0; 
            virtual void PollEvents() = 0;
            
            virtual int GetX() = 0;
            virtual int GetY() = 0; 

            virtual void SetX(int x) { SetPosition(x, GetY()); }
            virtual void SetY(int y) { SetPosition(GetX(), y); }
            virtual void SetPosition(int x, int y) = 0; 

            virtual int GetWidth() = 0; 
            virtual int GetHeight() = 0;

            virtual void SetWidth(int width) { SetSize(width, GetHeight()); }
            virtual void SetHeight(int height) { SetSize(GetWidth(), height); } 
            virtual void SetSize(int width, int height) = 0; 

            virtual double GetMouseX() = 0;
            virtual double GetMouseY() = 0;

            virtual void SetMouseX(double x) { SetMousePosition(x, GetMouseY()); }
            virtual void SetMouseY(double y) { SetMousePosition(GetMouseX(), y); }
            virtual void SetMousePosition(double x, double y) = 0; 

            virtual const std::string& GetTitle() = 0;
            virtual void SetTitle(const std::string& title) = 0; 

            virtual bool IsRunning() = 0; 

            virtual bool IsInitialized() { return m_Initialized; }
            virtual const std::string& GetInitializeErrorHint() { return m_InitializeErrorHint; }
            
        protected:
            bool m_Initialized = true;
            std::string m_InitializeErrorHint; 

    };
};