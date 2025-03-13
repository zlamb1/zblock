#include <glad/glad.h>

#include <gl/glshader.hpp>
#include <gl/render.hpp>
#include <ref.hpp>

namespace GL
{
    void RenderCore::SetViewport(int x, int y, int width, int height)
    {
        glViewport(x, y, width, height); 
    }

    Ref<Shader> RenderCore::CreateShader(ShaderType shaderType)
    {
        return CreateRef<GLShader>(shaderType); 
    }

    Ref<ShaderProgram> RenderCore::CreateProgram()
    {
        return CreateRef<GLShaderProgram>(); 
    }
};