#pragma once

#include "window/window.hpp"
#include <array>

#include <event/window.hpp>

#include <window/mouse.hpp>

namespace ZG
{
    class MouseEvent : public ZG::WindowEvent
    {
        public:
            MouseEvent(ZG::Window& window) : ZG::WindowEvent(window)
            {

            }

            const double GetX() { return m_X; }
            const double GetY() { return m_Y; }
            const std::array<bool, 8> GetButtons() const { return m_Buttons; }
            
        protected:
            double m_X, m_Y; 
            std::array<bool, 8> m_Buttons;
            
    };
};