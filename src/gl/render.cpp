#include <glad/glad.h>

#include <gl/debug.hpp>
#include <gl/shader.hpp>
#include <gl/render.hpp>

#include <ref.hpp>

namespace GL
{
    void RenderCore::SetViewport(int x, int y, int width, int height)
    {
        GLCall(glViewport(x, y, width, height)); 
    }

    Ref<ZG::Shader> RenderCore::CreateShader(ZG::ShaderType shaderType)
    {
        return CreateRef<GL::Shader>(shaderType); 
    }

    Ref<ZG::ShaderProgram> RenderCore::CreateProgram()
    {
        return CreateRef<GL::ShaderProgram>(); 
    }
};