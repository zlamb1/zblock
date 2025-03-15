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

            virtual bool SetBoolean(const std::string& uniformName, bool b) override; 
            virtual bool SetInteger(const std::string& uniformName, int i) override; 
            virtual bool SetFloat(const std::string& uniformName, float f) override; 
            
            virtual bool SetVec3f(const std::string& uniformName, const glm::vec3& vec) override;
            virtual bool SetVec4f(const std::string& uniformName, const glm::vec4& vec) override;

            virtual bool SetMat3f(const std::string& uniformName, const glm::mat3& mat) override;
            virtual bool SetMat4f(const std::string& uniformName, const glm::mat4& mat) override;

        protected:
            GLint GetUniformLocation(const std::string& uniformName); 

    };
};