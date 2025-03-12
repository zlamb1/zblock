#pragma once

#include <glad/glad.h>
#include <shader.hpp>

#include <GLFW/glfw3.h>

class GLShader : public Shader
{
    public:
        GLShader(ShaderType shaderType);
        virtual ~GLShader() override; 

        virtual bool CompileShader(const char *shaderCode) override; 
    
    protected:
        static GLenum GetGLShaderType(ShaderType shaderType); 

};

class GLShaderProgram : public ShaderProgram
{
    public:
        GLShaderProgram();
        virtual ~GLShaderProgram() override;

        virtual bool CompileProgram() override; 
        virtual bool BindProgram() override; 
};