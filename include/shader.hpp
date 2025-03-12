#pragma once

#include <algorithm>
#include <ref.hpp>
#include <resource.hpp>
#include <string>
#include <types.hpp>
#include <vector>

enum ShaderType
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

    protected:
        std::string m_CompileError; 
        std::vector<Ref<Shader>> m_Shaders;  

};