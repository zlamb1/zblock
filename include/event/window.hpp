#pragma once

#include <event/event.hpp>
#include <window/window.hpp>

namespace ZG
{
    class WindowEvent : public Event
    {
        public:
            WindowEvent(ZG::Window& window) : m_Window(window) {}

            ZG::Window& GetWindow() const { return m_Window; }

        protected:
            ZG::Window& m_Window;

    };
    
    class WindowSizeEvent : public WindowEvent
    {
        public:
            WindowSizeEvent(ZG::Window& window) : WindowEvent(window), m_Width(window.GetWidth()), m_Height(window.GetHeight()) {}
            WindowSizeEvent(ZG::Window& window, int width, int height) : WindowEvent(window), m_Width(width), m_Height(height) {}
            
            int GetWidth() const { return m_Width; }
            int GetHeight() const { return m_Height; }

        protected:
            uint m_Width, m_Height;
    };
}