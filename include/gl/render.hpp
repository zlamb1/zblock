#pragma once

#include "render/texture.hpp"
#include <render/render.hpp>

namespace GL
{
    class RenderCore : public ZG::RenderCore
    {
        public:
            RenderCore() = default;
            virtual ~RenderCore() = default; 

            virtual void SetViewport(int x, int y, int width, int height) override; 

            virtual Ref<ZG::Shader> CreateShader(ZG::ShaderType shaderType) override;
            virtual Ref<ZG::ShaderProgram> CreateProgram() override;
            virtual Ref<ZG::Texture2D> CreateTexture2D() override; 

    };
};