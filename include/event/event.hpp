#pragma once

namespace ZG
{
    enum class EventType : int
    {
        WindowSize,
        WindowFocus,
        MouseClick,
        MouseMove,
        KeyPress
    };

    class Event
    {
        public:
            virtual ~Event() = default; 

            virtual EventType GetEventType() const = 0;

    };
}