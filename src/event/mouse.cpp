#include <ref.hpp>

#include <event/mouse.hpp>

#include <window/window.hpp>

namespace ZG
{
    MouseEvent::MouseEvent(Ref<Window> window) : WindowEvent(window)
    {
        m_X = window->GetMouseX();
        m_Y = window->GetMouseY();
        m_Buttons[0] = window->IsMouseButtonClicked(MouseButton::ONE);
        m_Buttons[1] = window->IsMouseButtonClicked(MouseButton::TWO);
        m_Buttons[2] = window->IsMouseButtonClicked(MouseButton::THREE);
        m_Buttons[3] = window->IsMouseButtonClicked(MouseButton::FOUR);
        m_Buttons[4] = window->IsMouseButtonClicked(MouseButton::FIVE);
        m_Buttons[5] = window->IsMouseButtonClicked(MouseButton::SIX);
        m_Buttons[6] = window->IsMouseButtonClicked(MouseButton::SEVEN);
        m_Buttons[7] = window->IsMouseButtonClicked(MouseButton::EIGHT);
    }

    const double MouseEvent::GetX() const { return m_X; }
    const double MouseEvent::GetY() const { return m_Y; }

    bool MouseEvent::IsMouseButtonDown(MouseButton button) const
    {
        switch (button)
        {
            case MouseButton::ONE:
                return m_Buttons[0]; 
            case MouseButton::TWO:
                return m_Buttons[1]; 
            case MouseButton::THREE:
                return m_Buttons[2]; 
            case MouseButton::FOUR:
                return m_Buttons[3]; 
            case MouseButton::FIVE:
                return m_Buttons[4]; 
            case MouseButton::SIX:
                return m_Buttons[5]; 
            case MouseButton::SEVEN:
                return m_Buttons[6]; 
            case MouseButton::EIGHT:
                return m_Buttons[7]; 
            default:
                return false; 
        }
    }

    MouseClickEvent::MouseClickEvent(Ref<Window> window, MouseAction action, MouseButton button) : MouseEvent(window)
    {
        m_Action = action;
        m_Button = button; 
    }

    EventType MouseClickEvent::GetEventType() const { return EventType::MouseClick; }

    MouseAction MouseClickEvent::GetAction() { return m_Action; }
    MouseButton MouseClickEvent::GetButton() { return m_Button; }

    MouseMoveEvent::MouseMoveEvent(Ref<Window> window) : MouseEvent(window) 
    {
    }

    EventType MouseMoveEvent::GetEventType() const { return EventType::MouseMove; }
};