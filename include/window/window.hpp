#pragma once

#include "window/kb.hpp"
#include <string>
#include <types.hpp>

#include <event/callback.hpp>
#include <event/dispatch.hpp>
#include <event/mouse.hpp>
#include <event/window.hpp>

#include <window/mouse.hpp>

namespace ZG
{
    using WindowSizeCallback = EventCallback<WindowSizeEvent>; 
    using MouseClickCallback = EventCallback<MouseClickEvent>;
    using MouseMoveCallback = EventCallback<MouseMoveEvent>; 

    class Window : public std::enable_shared_from_this<Window>, public EventDisptacher
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
            
            virtual void SetMouseCentered()
            {
                int halfWidth = GetWidth() / 2, halfHeight = GetHeight() / 2;
                SetMousePosition(halfWidth, halfHeight);  
            } 

            virtual bool IsMouseButtonClicked(MouseButton button) = 0; 

            virtual void ShowCursor() = 0;
            virtual void HideCursor() = 0; 

            virtual KeyAction GetKeyState(KeyCode keyCode) = 0; 
            virtual bool IsKeyPressed(KeyCode keyCode) { return GetKeyState(keyCode) == KeyAction::PRESS; }

            virtual bool IsFocused() = 0; 

            virtual const std::string& GetTitle() = 0;
            virtual void SetTitle(const std::string& title) = 0; 

            virtual bool IsRunning() = 0; 

            virtual bool IsInitialized() { return m_Initialized; }
            virtual const std::string& GetInitializeErrorHint() { return m_InitializeErrorHint; }

            Ref<Window> GetRef() { return shared_from_this(); }

        protected:
            bool m_Initialized = true;
            std::string m_InitializeErrorHint; 

    };
};