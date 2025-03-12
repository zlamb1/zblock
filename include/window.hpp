#pragma once

#include <string>
#include <types.hpp>

namespace ZG
{
    class Window
    {
        public:
            Window() = default;
            virtual ~Window() = default;

            virtual void MakeContextCurrent() = 0; 
            virtual void SwapBuffers() = 0; 

            virtual void SetSize(uint width, uint height) = 0; 
            virtual void SetTitle(const std::string& title) = 0; 

            virtual uint GetWidth() = 0; 
            virtual uint GetHeight() = 0; 

            virtual const std::string& GetTitle() = 0;

            virtual bool IsRunning() = 0; 

            virtual bool IsInitialized() { return m_Initialized; }
            virtual const std::string& GetInitializeErrorHint() { return m_InitializeErrorHint; }

        protected:
            bool m_Initialized = true;
            std::string m_InitializeErrorHint; 

    };
};