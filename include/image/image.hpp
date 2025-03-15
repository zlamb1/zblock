#pragma once

#include <ref.hpp>

class Image
{
    public:
        virtual ~Image() = default; 

        virtual void *GetData() const { return m_Data; }

        virtual int GetWidth() const { return m_Width; }
        virtual int GetHeight() const { return m_Height;  }

    protected:
        void *m_Data;
        int m_Width, m_Height; 

};