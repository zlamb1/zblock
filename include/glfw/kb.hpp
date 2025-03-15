#pragma once

#include <GLFW/glfw3.h>

#include <window/kb.hpp>

#ifdef ZG_ENSURE_GLFW_KEY_CODE_PARITY

#if ZG_KEY_UNKNOWN != GLFW_KEY_UNKNOWN
#error ZG_KEY_UNKNOWN != GLFW_KEY_UNKNOWN
#endif
#if ZG_KEY_SPACE != GLFW_KEY_SPACE
#error ZG_KEY_SPACE != GLFW_KEY_SPACE
#endif
#if ZG_KEY_APOSTROPHE != GLFW_KEY_APOSTROPHE
#error ZG_KEY_APOSTROPHE != GLFW_KEY_APOSTROPHE
#endif
#if ZG_KEY_COMMA != GLFW_KEY_COMMA
#error ZG_KEY_COMMA != GLFW_KEY_COMMA
#endif
#if ZG_KEY_MINUS != GLFW_KEY_MINUS
#error ZG_KEY_MINUS != GLFW_KEY_MINUS
#endif
#if ZG_KEY_PERIOD != GLFW_KEY_PERIOD
#error ZG_KEY_PERIOD != GLFW_KEY_PERIOD
#endif
#if ZG_KEY_SLASH != GLFW_KEY_SLASH
#error ZG_KEY_SLASH != GLFW_KEY_SLASH
#endif
#if ZG_KEY_0 != GLFW_KEY_0
#error ZG_KEY_0 != GLFW_KEY_0
#endif
#if ZG_KEY_1 != GLFW_KEY_1
#error ZG_KEY_1 != GLFW_KEY_1
#endif
#if ZG_KEY_2 != GLFW_KEY_2
#error ZG_KEY_2 != GLFW_KEY_2
#endif
#if ZG_KEY_3 != GLFW_KEY_3
#error ZG_KEY_3 != GLFW_KEY_3
#endif
#if ZG_KEY_4 != GLFW_KEY_4
#error ZG_KEY_4 != GLFW_KEY_4
#endif
#if ZG_KEY_5 != GLFW_KEY_5
#error ZG_KEY_5 != GLFW_KEY_5
#endif
#if ZG_KEY_6 != GLFW_KEY_6
#error ZG_KEY_SIX != GLFW_KEY_6
#endif
#if ZG_KEY_7 != GLFW_KEY_7
#error ZG_KEY_7 != GLFW_KEY_7
#endif
#if ZG_KEY_8 != GLFW_KEY_8
#error ZG_KEY_8 != GLFW_KEY_8
#endif
#if ZG_KEY_9 != GLFW_KEY_9
#error ZG_KEY_9 != GLFW_KEY_9
#endif
#if ZG_KEY_SEMICOLON != GLFW_KEY_SEMICOLON
#error ZG_KEY_SEMICOLON != GLFW_KEY_SEMICOLON
#endif
#if ZG_KEY_EQUAL != GLFW_KEY_EQUAL
#error ZG_KEY_EQUAL != GLFW_KEY_EQUAL
#endif
#if ZG_KEY_A != GLFW_KEY_A
#error ZG_KEY_A != GLFW_KEY_A
#endif
#if ZG_KEY_B != GLFW_KEY_B
#error ZG_KEY_B != GLFW_KEY_B
#endif
#if ZG_KEY_C != GLFW_KEY_C
#error ZG_KEY_C != GLFW_KEY_C
#endif
#if ZG_KEY_D != GLFW_KEY_D
#error ZG_KEY_D != GLFW_KEY_D
#endif
#if ZG_KEY_E != GLFW_KEY_E
#error ZG_KEY_E != GLFW_KEY_E
#endif
#if ZG_KEY_F != GLFW_KEY_F
#error ZG_KEY_F != GLFW_KEY_F
#endif
#if ZG_KEY_G != GLFW_KEY_G
#error ZG_KEY_G != GLFW_KEY_G
#endif
#if ZG_KEY_H != GLFW_KEY_H
#error ZG_KEY_H != GLFW_KEY_H
#endif
#if ZG_KEY_I != GLFW_KEY_I
#error ZG_KEY_I != GLFW_KEY_I
#endif
#if ZG_KEY_J != GLFW_KEY_J
#error ZG_KEY_J != GLFW_KEY_J
#endif
#if ZG_KEY_K != GLFW_KEY_K
#error ZG_KEY_K != GLFW_KEY_K
#endif
#if ZG_KEY_L != GLFW_KEY_L
#error ZG_KEY_L != GLFW_KEY_L
#endif
#if ZG_KEY_M != GLFW_KEY_M
#error ZG_KEY_M != GLFW_KEY_M
#endif
#if ZG_KEY_N != GLFW_KEY_N
#error ZG_KEY_N != GLFW_KEY_N
#endif
#if ZG_KEY_O != GLFW_KEY_O
#error ZG_KEY_O != GLFW_KEY_O
#endif
#if ZG_KEY_P != GLFW_KEY_P
#error ZG_KEY_P != GLFW_KEY_P
#endif
#if ZG_KEY_Q != GLFW_KEY_Q
#error ZG_KEY_Q != GLFW_KEY_Q
#endif
#if ZG_KEY_R != GLFW_KEY_R
#error ZG_KEY_R != GLFW_KEY_R
#endif
#if ZG_KEY_S != GLFW_KEY_S
#error ZG_KEY_S != GLFW_KEY_S
#endif
#if ZG_KEY_T != GLFW_KEY_T
#error ZG_KEY_T != GLFW_KEY_T
#endif
#if ZG_KEY_U != GLFW_KEY_U
#error ZG_KEY_U != GLFW_KEY_U
#endif
#if ZG_KEY_V != GLFW_KEY_V
#error ZG_KEY_V != GLFW_KEY_V
#endif
#if ZG_KEY_W != GLFW_KEY_W
#error ZG_KEY_W != GLFW_KEY_W
#endif
#if ZG_KEY_X != GLFW_KEY_X
#error ZG_KEY_X != GLFW_KEY_X
#endif
#if ZG_KEY_Y != GLFW_KEY_Y
#error ZG_KEY_Y != GLFW_KEY_Y
#endif
#if ZG_KEY_Z != GLFW_KEY_Z
#error ZG_KEY_Z != GLFW_KEY_Z
#endif
#if ZG_KEY_LEFT_BRACKET != GLFW_KEY_LEFT_BRACKET
#error ZG_KEY_LEFT_BRACKET != GLFW_KEY_LEFT_BRACKET
#endif
#if ZG_KEY_BACKSLASH != GLFW_KEY_BACKSLASH
#error ZG_KEY_BACKSLASH != GLFW_KEY_BACKSLASH
#endif
#if ZG_KEY_RIGHT_BRACKET != GLFW_KEY_RIGHT_BRACKET
#error ZG_KEY_RIGHT_BRACKET != GLFW_KEY_RIGHT_BRACKET
#endif
#if ZG_KEY_GRAVE_ACCENT != GLFW_KEY_GRAVE_ACCENT
#error ZG_KEY_GRAVE_ACCENT != GLFW_KEY_GRAVE_ACCENT
#endif
#if ZG_KEY_WORLD_1 != GLFW_KEY_WORLD_1
#error ZG_KEY_WORLD_1 != GLFW_KEY_WORLD_1
#endif
#if ZG_KEY_WORLD_2 != GLFW_KEY_WORLD_2
#error ZG_KEY_WORLD_2 != GLFW_KEY_WORLD_2
#endif
#if ZG_KEY_ESCAPE != GLFW_KEY_ESCAPE
#error ZG_KEY_ESCAPE != GLFW_KEY_ESCAPE
#endif
#if ZG_KEY_ENTER != GLFW_KEY_ENTER
#error ZG_KEY_ENTER != GLFW_KEY_ENTER
#endif
#if ZG_KEY_TAB != GLFW_KEY_TAB
#error ZG_KEY_TAB != GLFW_KEY_TAB
#endif
#if ZG_KEY_BACKSPACE != GLFW_KEY_BACKSPACE
#error ZG_KEY_BACKSPACE != GLFW_KEY_BACKSPACE
#endif
#if ZG_KEY_INSERT != GLFW_KEY_INSERT
#error ZG_KEY_INSERT != GLFW_KEY_INSERT
#endif
#if ZG_KEY_DELETE != GLFW_KEY_DELETE
#error ZG_KEY_DELETE != GLFW_KEY_DELETE
#endif
#if ZG_KEY_RIGHT != GLFW_KEY_RIGHT
#error ZG_KEY_RIGHT != GLFW_KEY_RIGHT
#endif
#if ZG_KEY_LEFT != GLFW_KEY_LEFT
#error ZG_KEY_LEFT != GLFW_KEY_LEFT
#endif
#if ZG_KEY_DOWN != GLFW_KEY_DOWN
#error ZG_KEY_DOWN != GLFW_KEY_DOWN
#endif
#if ZG_KEY_UP != GLFW_KEY_UP
#error ZG_KEY_UP != GLFW_KEY_UP
#endif
#if ZG_KEY_PAGE_UP != GLFW_KEY_PAGE_UP
#error ZG_KEY_PAGE_UP != GLFW_KEY_PAGE_UP
#endif
#if ZG_KEY_PAGE_DOWN != GLFW_KEY_PAGE_DOWN
#error ZG_KEY_PAGE_DOWN != GLFW_KEY_PAGE_DOWN
#endif
#if ZG_KEY_HOME != GLFW_KEY_HOME
#error ZG_KEY_HOME != GLFW_KEY_HOME
#endif
#if ZG_KEY_END != GLFW_KEY_END
#error ZG_KEY_END != GLFW_KEY_END
#endif
#if ZG_KEY_CAPS_LOCK != GLFW_KEY_CAPS_LOCK
#error ZG_KEY_CAPS_LOCK != GLFW_KEY_CAPS_LOCK
#endif
#if ZG_KEY_SCROLL_LOCK != GLFW_KEY_SCROLL_LOCK
#error ZG_KEY_SCROLL_LOCK != GLFW_KEY_SCROLL_LOCK
#endif
#if ZG_KEY_NUM_LOCK != GLFW_KEY_NUM_LOCK
#error ZG_KEY_NUM_LOCK != GLFW_KEY_NUM_LOCK
#endif
#if ZG_KEY_PRINT_SCREEN != GLFW_KEY_PRINT_SCREEN
#error ZG_KEY_PRINT_SCREEN != GLFW_KEY_PRINT_SCREEN
#endif
#if ZG_KEY_PAUSE != GLFW_KEY_PAUSE
#error ZG_KEY_PAUSE != GLFW_KEY_PAUSE
#endif
#if ZG_KEY_F1 != GLFW_KEY_F1
#error ZG_KEY_F1 != GLFW_KEY_F1
#endif
#if ZG_KEY_F2 != GLFW_KEY_F2
#error ZG_KEY_F2 != GLFW_KEY_F2
#endif
#if ZG_KEY_F3 != GLFW_KEY_F3
#error ZG_KEY_F3 != GLFW_KEY_F3
#endif
#if ZG_KEY_F4 != GLFW_KEY_F4
#error ZG_KEY_F4 != GLFW_KEY_F4
#endif
#if ZG_KEY_F5 != GLFW_KEY_F5
#error ZG_KEY_F5 != GLFW_KEY_F5
#endif
#if ZG_KEY_F6 != GLFW_KEY_F6
#error ZG_KEY_F6 != GLFW_KEY_F6
#endif
#if ZG_KEY_F7 != GLFW_KEY_F7
#error ZG_KEY_F7 != GLFW_KEY_F7
#endif
#if ZG_KEY_F8 != GLFW_KEY_F8
#error ZG_KEY_F8 != GLFW_KEY_F8
#endif
#if ZG_KEY_F9 != GLFW_KEY_F9
#error ZG_KEY_F9 != GLFW_KEY_F9
#endif
#if ZG_KEY_F10 != GLFW_KEY_F10
#error ZG_KEY_F10 != GLFW_KEY_F10
#endif
#if ZG_KEY_F11 != GLFW_KEY_F11
#error ZG_KEY_F11 != GLFW_KEY_F11
#endif
#if ZG_KEY_F12 != GLFW_KEY_F12
#error ZG_KEY_F12 != GLFW_KEY_F12
#endif
#if ZG_KEY_F13 != GLFW_KEY_F13
#error ZG_KEY_F13 != GLFW_KEY_F13
#endif
#if ZG_KEY_F14 != GLFW_KEY_F14
#error ZG_KEY_F14 != GLFW_KEY_F14
#endif
#if ZG_KEY_F15 != GLFW_KEY_F15
#error ZG_KEY_F15 != GLFW_KEY_F15
#endif
#if ZG_KEY_F16 != GLFW_KEY_F16
#error ZG_KEY_F16 != GLFW_KEY_F16
#endif
#if ZG_KEY_F17 != GLFW_KEY_F17
#error ZG_KEY_F17 != GLFW_KEY_F17
#endif
#if ZG_KEY_F18 != GLFW_KEY_F18
#error ZG_KEY_F18 != GLFW_KEY_F18
#endif
#if ZG_KEY_F19 != GLFW_KEY_F19
#error ZG_KEY_F19 != GLFW_KEY_F19
#endif
#if ZG_KEY_F20 != GLFW_KEY_F20
#error ZG_KEY_F20 != GLFW_KEY_F20
#endif
#if ZG_KEY_F21 != GLFW_KEY_F21
#error ZG_KEY_F21 != GLFW_KEY_F21
#endif
#if ZG_KEY_F22 != GLFW_KEY_F22
#error ZG_KEY_F22 != GLFW_KEY_F22
#endif
#if ZG_KEY_F23 != GLFW_KEY_F23
#error ZG_KEY_F23 != GLFW_KEY_F23
#endif
#if ZG_KEY_F24 != GLFW_KEY_F24
#error ZG_KEY_F24 != GLFW_KEY_F24
#endif
#if ZG_KEY_F25 != GLFW_KEY_F25
#error ZG_KEY_F25 != GLFW_KEY_F25
#endif
#if ZG_KEY_KP_0 != GLFW_KEY_KP_0
#error ZG_KEY_KP_0 != GLFW_KEY_KP_0
#endif
#if ZG_KEY_KP_1 != GLFW_KEY_KP_1
#error ZG_KEY_KP_1 != GLFW_KEY_KP_1
#endif
#if ZG_KEY_KP_2 != GLFW_KEY_KP_2
#error ZG_KEY_KP_2 != GLFW_KEY_KP_2
#endif
#if ZG_KEY_KP_3 != GLFW_KEY_KP_3
#error ZG_KEY_KP_3 != GLFW_KEY_KP_3
#endif
#if ZG_KEY_KP_4 != GLFW_KEY_KP_4
#error ZG_KEY_KP_4 != GLFW_KEY_KP_4
#endif
#if ZG_KEY_KP_5 != GLFW_KEY_KP_5
#error ZG_KEY_KP_5 != GLFW_KEY_KP_5
#endif
#if ZG_KEY_KP_6 != GLFW_KEY_KP_6
#error ZG_KEY_KP_6 != GLFW_KEY_KP_6
#endif
#if ZG_KEY_KP_7 != GLFW_KEY_KP_7
#error ZG_KEY_KP_7 != GLFW_KEY_KP_7
#endif
#if ZG_KEY_KP_8 != GLFW_KEY_KP_8
#error ZG_KEY_KP_8 != GLFW_KEY_KP_8
#endif
#if ZG_KEY_KP_9 != GLFW_KEY_KP_9
#error ZG_KEY_KP_9 != GLFW_KEY_KP_9
#endif
#if ZG_KEY_KP_DECIMAL != GLFW_KEY_KP_DECIMAL
#error ZG_KEY_KP_DECIMAL != GLFW_KEY_KP_DECIMAL
#endif
#if ZG_KEY_KP_DIVIDE != GLFW_KEY_KP_DIVIDE
#error ZG_KEY_KP_DIVIDE != GLFW_KEY_KP_DIVIDE
#endif
#if ZG_KEY_KP_MULTIPLY != GLFW_KEY_KP_MULTIPLY
#error ZG_KEY_KP_MULTIPLY != GLFW_KEY_KP_MULTIPLY
#endif
#if ZG_KEY_KP_SUBTRACT != GLFW_KEY_KP_SUBTRACT
#error ZG_KEY_KP_SUBTRACT != GLFW_KEY_KP_SUBTRACT
#endif
#if ZG_KEY_KP_ADD != GLFW_KEY_KP_ADD
#error ZG_KEY_KP_ADD != GLFW_KEY_KP_ADD
#endif
#if ZG_KEY_KP_ENTER != GLFW_KEY_KP_ENTER
#error ZG_KEY_KP_ENTER != GLFW_KEY_KP_ENTER
#endif
#if ZG_KEY_KP_EQUAL != GLFW_KEY_KP_EQUAL
#error ZG_KEY_KP_EQUAL != GLFW_KEY_KP_EQUAL
#endif
#if ZG_KEY_LEFT_SHIFT != GLFW_KEY_LEFT_SHIFT
#error ZG_KEY_LEFT_SHIFT != GLFW_KEY_LEFT_SHIFT
#endif
#if ZG_KEY_LEFT_CONTROL != GLFW_KEY_LEFT_CONTROL
#error ZG_KEY_LEFT_CONTROL != GLFW_KEY_LEFT_CONTROL
#endif
#if ZG_KEY_LEFT_ALT != GLFW_KEY_LEFT_ALT
#error ZG_KEY_LEFT_ALT != GLFW_KEY_LEFT_ALT
#endif
#if ZG_KEY_LEFT_SUPER != GLFW_KEY_LEFT_SUPER
#error ZG_KEY_LEFT_SUPER != GLFW_KEY_LEFT_SUPER
#endif
#if ZG_KEY_RIGHT_SHIFT != GLFW_KEY_RIGHT_SHIFT
#error ZG_KEY_RIGHT_SHIFT != GLFW_KEY_RIGHT_SHIFT
#endif
#if ZG_KEY_RIGHT_CONTROL != GLFW_KEY_RIGHT_CONTROL
#error ZG_KEY_RIGHT_CONTROL != GLFW_KEY_RIGHT_CONTROL
#endif
#if ZG_KEY_RIGHT_ALT != GLFW_KEY_RIGHT_ALT
#error ZG_KEY_RIGHT_ALT != GLFW_KEY_RIGHT_ALT
#endif
#if ZG_KEY_RIGHT_SUPER != GLFW_KEY_RIGHT_SUPER
#error ZG_KEY_RIGHT_SUPER != GLFW_KEY_RIGHT_SUPER
#endif
#if ZG_KEY_MENU != GLFW_KEY_MENU
#error ZG_KEY_MENU != GLFW_KEY_MENU
#endif
#if ZG_KEY_LAST != GLFW_KEY_LAST
#error ZG_KEY_LAST != GLFW_KEY_LAST
#endif

#endif

#define ZG_GLFW_KEY_CONV(C) \
switch (C) \
{ \
    case GLFW_KEY_UNKNOWN:       return ZG_KEY_UNKNOWN; \
    case GLFW_KEY_SPACE:         return ZG_KEY_SPACE; \
    case GLFW_KEY_APOSTROPHE:    return ZG_KEY_APOSTROPHE; \
    case GLFW_KEY_COMMA:         return ZG_KEY_COMMA; \
    case GLFW_KEY_MINUS:         return ZG_KEY_MINUS; \
    case GLFW_KEY_PERIOD:        return ZG_KEY_PERIOD; \
    case GLFW_KEY_SLASH:         return ZG_KEY_SLASH; \
    case GLFW_KEY_0:             return ZG_KEY_0; \
    case GLFW_KEY_1:             return ZG_KEY_1; \
    case GLFW_KEY_2:             return ZG_KEY_2; \
    case GLFW_KEY_3:             return ZG_KEY_3; \
    case GLFW_KEY_4:             return ZG_KEY_4; \
    case GLFW_KEY_5:             return ZG_KEY_5; \
    case GLFW_KEY_6:             return ZG_KEY_6; \
    case GLFW_KEY_7:             return ZG_KEY_7; \
    case GLFW_KEY_8:             return ZG_KEY_8; \
    case GLFW_KEY_9:             return ZG_KEY_9; \
    case GLFW_KEY_SEMICOLON:     return ZG_KEY_SEMICOLON; \
    case GLFW_KEY_EQUAL:         return ZG_KEY_EQUAL; \
    case GLFW_KEY_A:             return ZG_KEY_A; \
    case GLFW_KEY_B:             return ZG_KEY_B; \
    case GLFW_KEY_C:             return ZG_KEY_C; \
    case GLFW_KEY_D:             return ZG_KEY_D; \
    case GLFW_KEY_E:             return ZG_KEY_E; \
    case GLFW_KEY_F:             return ZG_KEY_F; \
    case GLFW_KEY_G:             return ZG_KEY_G; \
    case GLFW_KEY_H:             return ZG_KEY_H; \
    case GLFW_KEY_I:             return ZG_KEY_I; \
    case GLFW_KEY_J:             return ZG_KEY_J; \
    case GLFW_KEY_K:             return ZG_KEY_K; \
    case GLFW_KEY_L:             return ZG_KEY_L; \
    case GLFW_KEY_M:             return ZG_KEY_M; \
    case GLFW_KEY_N:             return ZG_KEY_N; \
    case GLFW_KEY_O:             return ZG_KEY_O; \
    case GLFW_KEY_P:             return ZG_KEY_P; \
    case GLFW_KEY_Q:             return ZG_KEY_Q; \
    case GLFW_KEY_R:             return ZG_KEY_R; \
    case GLFW_KEY_S:             return ZG_KEY_S; \
    case GLFW_KEY_T:             return ZG_KEY_T; \
    case GLFW_KEY_U:             return ZG_KEY_U; \
    case GLFW_KEY_V:             return ZG_KEY_V; \
    case GLFW_KEY_W:             return ZG_KEY_W; \
    case GLFW_KEY_X:             return ZG_KEY_X; \
    case GLFW_KEY_Y:             return ZG_KEY_Y; \
    case GLFW_KEY_Z:             return ZG_KEY_Z; \
    case GLFW_KEY_LEFT_BRACKET:  return ZG_KEY_LEFT_BRACKET; \
    case GLFW_KEY_BACKSLASH:     return ZG_KEY_BACKSLASH; \
    case GLFW_KEY_RIGHT_BRACKET: return ZG_KEY_RIGHT_BRACKET; \
    case GLFW_KEY_GRAVE_ACCENT:  return ZG_KEY_GRAVE_ACCENT; \
    case GLFW_KEY_WORLD_1:       return ZG_KEY_WORLD_1; \
    case GLFW_KEY_WORLD_2:       return ZG_KEY_WORLD_2; \
    case GLFW_KEY_ESCAPE:        return ZG_KEY_ESCAPE; \
    case GLFW_KEY_ENTER:         return ZG_KEY_ENTER; \
    case GLFW_KEY_TAB:           return ZG_KEY_TAB; \
    case GLFW_KEY_BACKSPACE:     return ZG_KEY_BACKSPACE; \
    case GLFW_KEY_INSERT:        return ZG_KEY_INSERT; \
    case GLFW_KEY_DELETE:        return ZG_KEY_DELETE; \
    case GLFW_KEY_RIGHT:         return ZG_KEY_RIGHT; \
    case GLFW_KEY_LEFT:          return ZG_KEY_LEFT; \
    case GLFW_KEY_DOWN:          return ZG_KEY_DOWN; \
    case GLFW_KEY_UP:            return ZG_KEY_UP; \
    case GLFW_KEY_PAGE_UP:       return ZG_KEY_PAGE_UP; \
    case GLFW_KEY_PAGE_DOWN:     return ZG_KEY_PAGE_DOWN; \
    case GLFW_KEY_HOME:          return ZG_KEY_HOME; \
    case GLFW_KEY_END:           return ZG_KEY_END; \
    case GLFW_KEY_CAPS_LOCK:     return ZG_KEY_CAPS_LOCK; \
    case GLFW_KEY_SCROLL_LOCK:   return ZG_KEY_SCROLL_LOCK; \
    case GLFW_KEY_NUM_LOCK:      return ZG_KEY_NUM_LOCK; \
    case GLFW_KEY_PRINT_SCREEN:  return ZG_KEY_PRINT_SCREEN; \
    case GLFW_KEY_PAUSE:         return ZG_KEY_PAUSE; \
    case GLFW_KEY_F1:            return ZG_KEY_F1; \
    case GLFW_KEY_F2:            return ZG_KEY_F2; \
    case GLFW_KEY_F3:            return ZG_KEY_F3; \
    case GLFW_KEY_F4:            return ZG_KEY_F4; \
    case GLFW_KEY_F5:            return ZG_KEY_F5; \
    case GLFW_KEY_F6:            return ZG_KEY_F6; \
    case GLFW_KEY_F7:            return ZG_KEY_F7; \
    case GLFW_KEY_F8:            return ZG_KEY_F8; \
    case GLFW_KEY_F9:            return ZG_KEY_F9; \
    case GLFW_KEY_F10:           return ZG_KEY_F10; \
    case GLFW_KEY_F11:           return ZG_KEY_F11; \
    case GLFW_KEY_F12:           return ZG_KEY_F12; \
    case GLFW_KEY_F13:           return ZG_KEY_F13; \
    case GLFW_KEY_F14:           return ZG_KEY_F14; \
    case GLFW_KEY_F15:           return ZG_KEY_F15; \
    case GLFW_KEY_F16:           return ZG_KEY_F16; \
    case GLFW_KEY_F17:           return ZG_KEY_F17; \
    case GLFW_KEY_F18:           return ZG_KEY_F18; \
    case GLFW_KEY_F19:           return ZG_KEY_F19; \
    case GLFW_KEY_F20:           return ZG_KEY_F20; \
    case GLFW_KEY_F21:           return ZG_KEY_F21; \
    case GLFW_KEY_F22:           return ZG_KEY_F22; \
    case GLFW_KEY_F23:           return ZG_KEY_F23; \
    case GLFW_KEY_F24:           return ZG_KEY_F24; \
    case GLFW_KEY_F25:           return ZG_KEY_F25; \
    case GLFW_KEY_KP_0:          return ZG_KEY_KP_0; \
    case GLFW_KEY_KP_1:          return ZG_KEY_KP_1; \
    case GLFW_KEY_KP_2:          return ZG_KEY_KP_2; \
    case GLFW_KEY_KP_3:          return ZG_KEY_KP_3; \
    case GLFW_KEY_KP_4:          return ZG_KEY_KP_4; \
    case GLFW_KEY_KP_5:          return ZG_KEY_KP_5; \
    case GLFW_KEY_KP_6:          return ZG_KEY_KP_6; \
    case GLFW_KEY_KP_7:          return ZG_KEY_KP_7; \
    case GLFW_KEY_KP_8:          return ZG_KEY_KP_8; \
    case GLFW_KEY_KP_9:          return ZG_KEY_KP_9; \
    case GLFW_KEY_KP_DECIMAL:    return ZG_KEY_KP_DECIMAL; \
    case GLFW_KEY_KP_DIVIDE:     return ZG_KEY_KP_DIVIDE; \
    case GLFW_KEY_KP_MULTIPLY:   return ZG_KEY_KP_MULTIPLY; \
    case GLFW_KEY_KP_SUBTRACT:   return ZG_KEY_KP_SUBTRACT; \
    case GLFW_KEY_KP_ADD:        return ZG_KEY_KP_ADD; \
    case GLFW_KEY_KP_ENTER:      return ZG_KEY_KP_ENTER; \
    case GLFW_KEY_KP_EQUAL:      return ZG_KEY_KP_EQUAL; \
    case GLFW_KEY_LEFT_SHIFT:    return ZG_KEY_LEFT_SHIFT; \
    case GLFW_KEY_LEFT_CONTROL:  return ZG_KEY_LEFT_CONTROL; \
    case GLFW_KEY_LEFT_ALT:      return ZG_KEY_LEFT_ALT; \
    case GLFW_KEY_LEFT_SUPER:    return ZG_KEY_LEFT_SUPER; \
    case GLFW_KEY_RIGHT_SHIFT:   return ZG_KEY_RIGHT_SHIFT; \
    case GLFW_KEY_RIGHT_CONTROL: return ZG_KEY_RIGHT_CONTROL; \
    case GLFW_KEY_RIGHT_ALT:     return ZG_KEY_RIGHT_ALT; \
    case GLFW_KEY_RIGHT_SUPER:   return ZG_KEY_RIGHT_SUPER; \
    case GLFW_KEY_MENU:          return ZG_KEY_MENU; \
    default:                     return ZG_KEY_UNKNOWN; \
}

#define GLFW_ZG_KEY_CONV(C) \
switch (C) \
{ \
    case ZG_KEY_UNKNOWN:       return GLFW_KEY_UNKNOWN; \
    case ZG_KEY_SPACE:         return GLFW_KEY_SPACE; \
    case ZG_KEY_APOSTROPHE:    return GLFW_KEY_APOSTROPHE; \
    case ZG_KEY_COMMA:         return GLFW_KEY_COMMA; \
    case ZG_KEY_MINUS:         return GLFW_KEY_MINUS; \
    case ZG_KEY_PERIOD:        return GLFW_KEY_PERIOD; \
    case ZG_KEY_SLASH:         return GLFW_KEY_SLASH; \
    case ZG_KEY_0:             return GLFW_KEY_0; \
    case ZG_KEY_1:             return GLFW_KEY_1; \
    case ZG_KEY_2:             return GLFW_KEY_2; \
    case ZG_KEY_3:             return GLFW_KEY_3; \
    case ZG_KEY_4:             return GLFW_KEY_4; \
    case ZG_KEY_5:             return GLFW_KEY_5; \
    case ZG_KEY_6:             return GLFW_KEY_6; \
    case ZG_KEY_7:             return GLFW_KEY_7; \
    case ZG_KEY_8:             return GLFW_KEY_8; \
    case ZG_KEY_9:             return GLFW_KEY_9; \
    case ZG_KEY_SEMICOLON:     return GLFW_KEY_SEMICOLON; \
    case ZG_KEY_EQUAL:         return GLFW_KEY_EQUAL; \
    case ZG_KEY_A:             return GLFW_KEY_A; \
    case ZG_KEY_B:             return GLFW_KEY_B; \
    case ZG_KEY_C:             return GLFW_KEY_C; \
    case ZG_KEY_D:             return GLFW_KEY_D; \
    case ZG_KEY_E:             return GLFW_KEY_E; \
    case ZG_KEY_F:             return GLFW_KEY_F; \
    case ZG_KEY_G:             return GLFW_KEY_G; \
    case ZG_KEY_H:             return GLFW_KEY_H; \
    case ZG_KEY_I:             return GLFW_KEY_I; \
    case ZG_KEY_J:             return GLFW_KEY_J; \
    case ZG_KEY_K:             return GLFW_KEY_K; \
    case ZG_KEY_L:             return GLFW_KEY_L; \
    case ZG_KEY_M:             return GLFW_KEY_M; \
    case ZG_KEY_N:             return GLFW_KEY_N; \
    case ZG_KEY_O:             return GLFW_KEY_O; \
    case ZG_KEY_P:             return GLFW_KEY_P; \
    case ZG_KEY_Q:             return GLFW_KEY_Q; \
    case ZG_KEY_R:             return GLFW_KEY_R; \
    case ZG_KEY_S:             return GLFW_KEY_S; \
    case ZG_KEY_T:             return GLFW_KEY_T; \
    case ZG_KEY_U:             return GLFW_KEY_U; \
    case ZG_KEY_V:             return GLFW_KEY_V; \
    case ZG_KEY_W:             return GLFW_KEY_W; \
    case ZG_KEY_X:             return GLFW_KEY_X; \
    case ZG_KEY_Y:             return GLFW_KEY_Y; \
    case ZG_KEY_Z:             return GLFW_KEY_Z; \
    case ZG_KEY_LEFT_BRACKET:  return GLFW_KEY_LEFT_BRACKET; \
    case ZG_KEY_BACKSLASH:     return GLFW_KEY_BACKSLASH; \
    case ZG_KEY_RIGHT_BRACKET: return GLFW_KEY_RIGHT_BRACKET; \
    case ZG_KEY_GRAVE_ACCENT:  return GLFW_KEY_GRAVE_ACCENT; \
    case ZG_KEY_WORLD_1:       return GLFW_KEY_WORLD_1; \
    case ZG_KEY_WORLD_2:       return GLFW_KEY_WORLD_2; \
    case ZG_KEY_ESCAPE:        return GLFW_KEY_ESCAPE; \
    case ZG_KEY_ENTER:         return GLFW_KEY_ENTER; \
    case ZG_KEY_TAB:           return GLFW_KEY_TAB; \
    case ZG_KEY_BACKSPACE:     return GLFW_KEY_BACKSPACE; \
    case ZG_KEY_INSERT:        return GLFW_KEY_INSERT; \
    case ZG_KEY_DELETE:        return GLFW_KEY_DELETE; \
    case ZG_KEY_RIGHT:         return GLFW_KEY_RIGHT; \
    case ZG_KEY_LEFT:          return GLFW_KEY_LEFT; \
    case ZG_KEY_DOWN:          return GLFW_KEY_DOWN; \
    case ZG_KEY_UP:            return GLFW_KEY_UP; \
    case ZG_KEY_PAGE_UP:       return GLFW_KEY_PAGE_UP; \
    case ZG_KEY_PAGE_DOWN:     return GLFW_KEY_PAGE_DOWN; \
    case ZG_KEY_HOME:          return GLFW_KEY_HOME; \
    case ZG_KEY_END:           return GLFW_KEY_END; \
    case ZG_KEY_CAPS_LOCK:     return GLFW_KEY_CAPS_LOCK; \
    case ZG_KEY_SCROLL_LOCK:   return GLFW_KEY_SCROLL_LOCK; \
    case ZG_KEY_NUM_LOCK:      return GLFW_KEY_NUM_LOCK; \
    case ZG_KEY_PRINT_SCREEN:  return GLFW_KEY_PRINT_SCREEN; \
    case ZG_KEY_PAUSE:         return GLFW_KEY_PAUSE; \
    case ZG_KEY_F1:            return GLFW_KEY_F1; \
    case ZG_KEY_F2:            return GLFW_KEY_F2; \
    case ZG_KEY_F3:            return GLFW_KEY_F3; \
    case ZG_KEY_F4:            return GLFW_KEY_F4; \
    case ZG_KEY_F5:            return GLFW_KEY_F5; \
    case ZG_KEY_F6:            return GLFW_KEY_F6; \
    case ZG_KEY_F7:            return GLFW_KEY_F7; \
    case ZG_KEY_F8:            return GLFW_KEY_F8; \
    case ZG_KEY_F9:            return GLFW_KEY_F9; \
    case ZG_KEY_F10:           return GLFW_KEY_F10; \
    case ZG_KEY_F11:           return GLFW_KEY_F11; \
    case ZG_KEY_F12:           return GLFW_KEY_F12; \
    case ZG_KEY_F13:           return GLFW_KEY_F13; \
    case ZG_KEY_F14:           return GLFW_KEY_F14; \
    case ZG_KEY_F15:           return GLFW_KEY_F15; \
    case ZG_KEY_F16:           return GLFW_KEY_F16; \
    case ZG_KEY_F17:           return GLFW_KEY_F17; \
    case ZG_KEY_F18:           return GLFW_KEY_F18; \
    case ZG_KEY_F19:           return GLFW_KEY_F19; \
    case ZG_KEY_F20:           return GLFW_KEY_F20; \
    case ZG_KEY_F21:           return GLFW_KEY_F21; \
    case ZG_KEY_F22:           return GLFW_KEY_F22; \
    case ZG_KEY_F23:           return GLFW_KEY_F23; \
    case ZG_KEY_F24:           return GLFW_KEY_F24; \
    case ZG_KEY_F25:           return GLFW_KEY_F25; \
    case ZG_KEY_KP_0:          return GLFW_KEY_KP_0; \
    case ZG_KEY_KP_1:          return GLFW_KEY_KP_1; \
    case ZG_KEY_KP_2:          return GLFW_KEY_KP_2; \
    case ZG_KEY_KP_3:          return GLFW_KEY_KP_3; \
    case ZG_KEY_KP_4:          return GLFW_KEY_KP_4; \
    case ZG_KEY_KP_5:          return GLFW_KEY_KP_5; \
    case ZG_KEY_KP_6:          return GLFW_KEY_KP_6; \
    case ZG_KEY_KP_7:          return GLFW_KEY_KP_7; \
    case ZG_KEY_KP_8:          return GLFW_KEY_KP_8; \
    case ZG_KEY_KP_9:          return GLFW_KEY_KP_9; \
    case ZG_KEY_KP_DECIMAL:    return GLFW_KEY_KP_DECIMAL; \
    case ZG_KEY_KP_DIVIDE:     return GLFW_KEY_KP_DIVIDE; \
    case ZG_KEY_KP_MULTIPLY:   return GLFW_KEY_KP_MULTIPLY; \
    case ZG_KEY_KP_SUBTRACT:   return GLFW_KEY_KP_SUBTRACT; \
    case ZG_KEY_KP_ADD:        return GLFW_KEY_KP_ADD; \
    case ZG_KEY_KP_ENTER:      return GLFW_KEY_KP_ENTER; \
    case ZG_KEY_KP_EQUAL:      return GLFW_KEY_KP_EQUAL; \
    case ZG_KEY_LEFT_SHIFT:    return GLFW_KEY_LEFT_SHIFT; \
    case ZG_KEY_LEFT_CONTROL:  return GLFW_KEY_LEFT_CONTROL; \
    case ZG_KEY_LEFT_ALT:      return GLFW_KEY_LEFT_ALT; \
    case ZG_KEY_LEFT_SUPER:    return GLFW_KEY_LEFT_SUPER; \
    case ZG_KEY_RIGHT_SHIFT:   return GLFW_KEY_RIGHT_SHIFT; \
    case ZG_KEY_RIGHT_CONTROL: return GLFW_KEY_RIGHT_CONTROL; \
    case ZG_KEY_RIGHT_ALT:     return GLFW_KEY_RIGHT_ALT; \
    case ZG_KEY_RIGHT_SUPER:   return GLFW_KEY_RIGHT_SUPER; \
    case ZG_KEY_MENU:          return GLFW_KEY_MENU; \
    default:                   return GLFW_KEY_UNKNOWN; \
}

static int GLFWConvertKeyCode(int keyCode)
{
    ZG_GLFW_KEY_CONV(keyCode);
}

static int KeyCodeConvertGLFW(ZG::KeyCode keyCode)
{
    GLFW_ZG_KEY_CONV((int) keyCode);
}