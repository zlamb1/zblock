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
            WindowSizeEvent(ZG::Window& window, uint width, uint height) : WindowEvent(window), m_Width(width), m_Height(height) {}

            uint GetWidth() const { return m_Width; }
            uint GetHeight() const { return m_Height; }

        protected:
            uint m_Width, m_Height;
    };
}