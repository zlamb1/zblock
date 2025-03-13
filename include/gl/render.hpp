#pragma once

#include <render.hpp>

namespace GL
{
    class RenderCore : public ZG::RenderCore
    {
        public:
            RenderCore() = default;
            virtual ~RenderCore() = default; 

            virtual void SetViewport(int x, int y, int width, int height) override; 

            virtual Ref<Shader> CreateShader(ShaderType shaderType) override;
            virtual Ref<ShaderProgram> CreateProgram() override;

    };
};