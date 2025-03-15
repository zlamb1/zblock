#pragma once

#include <array>

#include <event/window.hpp>

#include <window/mouse.hpp>

namespace ZG
{
    class MouseEvent : public WindowEvent
    {
        public:
            MouseEvent(Ref<Window> window);

            virtual const double GetX() const;
            virtual const double GetY() const;

            virtual bool IsMouseButtonDown(MouseButton button) const;

        protected:
            double m_X, m_Y; 
            std::array<bool, 8> m_Buttons;
            
    };

    class MouseClickEvent : public MouseEvent
    {
        public:
            MouseClickEvent(Ref<Window> window, MouseAction action, MouseButton button);

            EventType GetEventType() const override;

            MouseAction GetAction();
            MouseButton GetButton();

        protected:
            MouseAction m_Action;
            MouseButton m_Button;

    };

    class MouseMoveEvent : public MouseEvent
    {
        public:
            MouseMoveEvent(Ref<Window> window);

            EventType GetEventType() const override;
    };
};