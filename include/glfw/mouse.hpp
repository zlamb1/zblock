#pragma once

#include <GLFW/glfw3.h>

#include <window/mouse.hpp>

#define ZG_GLFW_MOUSE_ACTION_CONV(A) \
switch(A) \
{ \
    case GLFW_PRESS:   return ZG::MouseAction::PRESS; \
    case GLFW_RELEASE: return ZG::MouseAction::RELEASE; \
    default:           return ZG::MouseAction::RELEASE; \
}

#define ZG_GLFW_MOUSE_BTN_CONV(B) \
switch (B) \
{ \
    case GLFW_MOUSE_BUTTON_1: return ZG::MouseButton::ONE; \
    case GLFW_MOUSE_BUTTON_2: return ZG::MouseButton::TWO; \
    case GLFW_MOUSE_BUTTON_3: return ZG::MouseButton::THREE; \
    case GLFW_MOUSE_BUTTON_4: return ZG::MouseButton::FOUR; \
    case GLFW_MOUSE_BUTTON_5: return ZG::MouseButton::FIVE; \
    case GLFW_MOUSE_BUTTON_6: return ZG::MouseButton::SIX; \
    case GLFW_MOUSE_BUTTON_7: return ZG::MouseButton::SEVEN; \
    case GLFW_MOUSE_BUTTON_8: return ZG::MouseButton::EIGHT; \
    default:                  return ZG::MouseButton::UNKNOWN; \
}