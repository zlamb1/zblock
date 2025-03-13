#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <render/shader.hpp>

namespace GL
{
    class Shader : public ZG::Shader
    {
        public:
            Shader(ZG::ShaderType shaderType);
            virtual ~Shader() override; 

            virtual bool CompileShader(const char *shaderCode) override; 
        
        protected:
            static GLenum GetGLShaderType(ZG::ShaderType shaderType); 

    };

    class ShaderProgram : public ZG::ShaderProgram
    {
        public:
            ShaderProgram();
            virtual ~ShaderProgram() override;

            virtual bool CompileProgram() override; 
            virtual bool BindProgram() override; 
    };
};