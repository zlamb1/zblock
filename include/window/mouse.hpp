#pragma once

namespace ZG
{
    enum class MouseAction : int
    {
        PRESS, RELEASE
    };

    enum class MouseButton : int
    {
        UNKNOWN = -1,

        LEFT, 
        RIGHT, 
        MIDDLE, 

        ONE = LEFT,
        TWO = RIGHT,
        THREE = MIDDLE,
        FOUR,
        FIVE, 
        SIX,
        SEVEN, 
        EIGHT,
    };
};