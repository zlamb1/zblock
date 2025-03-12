#pragma once

#include <types.hpp>

template<typename T>
class ResourceHandle
{
    public:
        virtual T GetHandle() const { return m_Handle; }

    protected:
        T m_Handle;
};