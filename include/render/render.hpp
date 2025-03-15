#pragma once

#include <types.hpp>

#include <render/shader.hpp>
#include <render/texture.hpp>

#include <window/window.hpp>

namespace ZG
{
    class RenderCore
    {
        public:
            RenderCore() = default;
            virtual ~RenderCore() = default;

            virtual bool InitializeCore() = 0;
            
            virtual const std::string& GetInitializeError() { return m_InitializeError; }

            virtual bool MakeContextCurrent(Ref<Window> window) = 0; 

            virtual void SetSwapInterval(int swapInterval) = 0; 
            virtual void SetViewport(int x, int y, int width, int height) = 0; 

            virtual Ref<Shader> CreateShader(ShaderType shaderType) = 0;
            virtual Ref<ShaderProgram> CreateProgram() = 0;
            virtual Ref<Texture2D> CreateTexture2D() = 0; 
            virtual Ref<Window> CreateWindow() = 0; 
            virtual Ref<Window> CreateWindow(int width, int height) = 0; 

        protected:
            std::string m_InitializeError;
    };
};