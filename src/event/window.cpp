#include <ref.hpp>

#include <event/window.hpp>

#include <window/window.hpp>

namespace ZG
{
    WindowEvent::WindowEvent(Ref<Window> window)
    {
        m_Window = window;
        m_WindowFocused = window->IsFocused();
    }

    WeakRef<Window> WindowEvent::GetWindow() const
    {
        return m_Window;
    }

    bool WindowEvent::IsWindowFocused() const
    {
        return m_WindowFocused; 
    }

    WindowSizeEvent::WindowSizeEvent(Ref<Window> window) : WindowEvent(window)
    {
        m_Width = window->GetWidth();
        m_Height = window->GetHeight(); 
    }

    EventType WindowSizeEvent::GetEventType() const
    { 
        return EventType::WindowSize; 
    }

    int WindowSizeEvent::GetWidth() const 
    {
        return m_Width;
    }

    int WindowSizeEvent::GetHeight() const
    {
        return m_Height;
    }
};