#pragma once

#include <ref.hpp>

#include <event/event.hpp>

namespace ZG
{
    class Window; 

    class WindowEvent : public Event
    {
        public:
            WindowEvent(Ref<Window> window);
            WeakRef<Window> GetWindow() const;

            bool IsWindowFocused() const; 

        protected:
            WeakRef<Window> m_Window;
            bool m_WindowFocused;

    };
    
    class WindowSizeEvent : public WindowEvent
    {
        public:
            WindowSizeEvent(Ref<Window> window);

            virtual EventType GetEventType() const override;

            int GetWidth() const;
            int GetHeight() const;
            
        protected:
            int m_Width, m_Height;

    };

    class WindowFocusEvent : public WindowEvent
    {
        public:
            WindowFocusEvent(Ref<Window> window) : WindowEvent(window) 
            {
            }

            virtual EventType GetEventType() const override { return EventType::WindowFocus; }

    };
}