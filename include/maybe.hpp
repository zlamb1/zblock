#pragma once

#include <string>

template<typename T>
class Maybe
{
    public:
        Maybe(T value) : m_HasValue(true), m_Value(value)
        {
        }

        bool HasValue()
        {
            return m_HasValue;
        }

        T GetValue()
        {
            return m_Value; 
        }

        const std::string& GetError()
        {
            return m_Error; 
        } 

        static Maybe error(const std::string& error)
        {
            return Maybe(error); 
        }

    protected:
        bool m_HasValue;
        T m_Value; 
        std::string m_Error; 

        Maybe(std::string error) : m_HasValue(false), m_Error(error)
        {
        }
        
};