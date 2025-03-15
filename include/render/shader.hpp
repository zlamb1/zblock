#pragma once

#include <algorithm>
#include <string>
#include <vector>

#include <ref.hpp>
#include <resource.hpp>
#include <types.hpp>

#include <glm/glm.hpp>

namespace ZG
{
    enum class ShaderType : int
    {
        VERTEX,
        FRAGMENT
    };

    class Shader : public ResourceHandle<uint>
    {
        public:
            Shader(ShaderType shaderType) : m_ShaderType(shaderType) {}
            virtual ~Shader() = default; 

            virtual bool CompileShader(const char *shaderCode) = 0; 

            ShaderType GetShaderType() const { return m_ShaderType; }
            const std::string& GetCompileError() const { return m_CompileError; }

        protected:
            ShaderType m_ShaderType;
            std::string m_CompileError; 

    };

    class ShaderProgram : public ResourceHandle<uint>
    {
        public:
            ShaderProgram() = default;
            virtual ~ShaderProgram() = default;
            
            virtual void AttachShader(Ref<Shader> shader) { m_Shaders.emplace_back(shader); }
            virtual bool DetatchShader(Ref<Shader> shader)
            {
                auto iter = std::find(m_Shaders.begin(), m_Shaders.end(), shader); 
                if (iter != m_Shaders.end())
                {
                    m_Shaders.erase(iter);
                    return true; 
                }
                return false;
            }

            virtual const std::string& GetCompileError() const { return m_CompileError; }

            virtual bool CompileProgram() = 0; 
            virtual bool BindProgram() = 0; 
            
            virtual bool SetBoolean(const std::string& uniformName, bool b) = 0; 
            virtual bool SetInteger(const std::string& uniformName, int i) = 0; 
            virtual bool SetFloat(const std::string& uniformName, float f) = 0; 
            
            virtual bool SetVec3f(const std::string& uniformName, const glm::vec3& vec) = 0;
            virtual bool SetVec4f(const std::string& uniformName, const glm::vec4& vec) = 0;

            virtual bool SetMat3f(const std::string& uniformName, const glm::mat3& mat) = 0;
            virtual bool SetMat4f(const std::string& uniformName, const glm::mat4& mat) = 0; 

        protected:
            std::string m_CompileError; 
            std::vector<Ref<Shader>> m_Shaders;  

    };
};