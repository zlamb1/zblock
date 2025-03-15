#pragma once

enum class TimeMeasure : int
{
    MILLISECONDS,
    SECONDS,
    MINUTES
};

class TimedAction
{
    public:
        TimedAction(double milliseconds)
        {
            m_MS = milliseconds; 
        }

        TimedAction(TimeMeasure timeMeasure, double time)
        {
            switch (timeMeasure)
            {
                case TimeMeasure::SECONDS:
                    m_MS = time * 1000.0;
                    break;
                case TimeMeasure::MINUTES:
                    m_MS = time * 1000.0 * 60.0;
                    break; 
                default:
                    m_MS = time;
                    break;
            }
        }

        virtual ~TimedAction() = default; 

        bool IsReady() const { return m_Time - m_LastAction > m_MS; }

        bool PerformAction(double time)
        {
            m_Time = time * 1000.0f; 
            bool ready = IsReady();
            if (ready)
                m_LastAction = time * 1000.0f; 
            return ready;
        }

    protected:
        double m_MS = 0; 
        double m_Time = 0;
        double m_LastAction = 0;

};