#pragma once

#include <gl/render.hpp>

namespace GLFW
{
    class GLRenderCore : public GL::RenderCore
    {
        public:
            virtual ~GLRenderCore() override;

            virtual bool InitializeCore() override;

            virtual bool MakeContextCurrent(Ref<ZG::Window> window) override; 

            virtual void SetSwapInterval(int swapInterval) override; 

            virtual Ref<ZG::Window> CreateWindow() override; 
            virtual Ref<ZG::Window> CreateWindow(int width, int height) override; 

        protected:

    };
};