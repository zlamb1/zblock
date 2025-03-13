#include <gl/debug.hpp>
#include <gl/shader.hpp>

#include <render/shader.hpp>

namespace GL
{
    Shader::Shader(ZG::ShaderType shaderType) : ZG::Shader(shaderType)
    {
        m_Handle = GLCall(glCreateShader(GetGLShaderType(shaderType)));
    }

    Shader::~Shader()
    {
        glDeleteShader(m_Handle);
    } 

    bool Shader::CompileShader(const char *shaderCode)
    {
        GLint success;

        GLCall(glShaderSource(m_Handle, 1, &shaderCode, NULL));
        GLCall(glCompileShader(m_Handle));
        GLCall(glGetShaderiv(m_Handle, GL_COMPILE_STATUS, &success));

        if (success != GL_TRUE)
        {
            GLchar infoLog[512]; 
            GLCall(glGetShaderInfoLog(m_Handle, 512, NULL, infoLog));
            m_CompileError = "SHADER::COMPILE::ERROR\n";
            m_CompileError += infoLog;
            return false;
        }

        return true;
    }

    GLenum Shader::GetGLShaderType(ZG::ShaderType shaderType)
    {
        switch (shaderType)
        {
            case ZG::ShaderType::VERTEX:
                return GL_VERTEX_SHADER;
            case ZG::ShaderType::FRAGMENT:
                return GL_FRAGMENT_SHADER; 
            default:
                return 0;
        }
    }

    ShaderProgram::ShaderProgram()
    {
        m_Handle = GLCall(glCreateProgram()); 
    }

    ShaderProgram::~ShaderProgram()
    {
        glDeleteProgram(m_Handle); 
    }

    bool ShaderProgram::CompileProgram()
    {
        GLint success;

        for (auto shader : m_Shaders)
            GLCall(glAttachShader(m_Handle, shader->GetHandle())); 

        GLCall(glLinkProgram(m_Handle));

        GLCall(glGetProgramiv(m_Handle, GL_LINK_STATUS, &success));

        if(success != GL_TRUE)
        {
            GLchar infoLog[512]; 
            GLCall(glGetProgramInfoLog(m_Handle, 512, NULL, infoLog));
            m_CompileError = "PROGRAM::COMPILE::ERROR\n";
            m_CompileError += infoLog; 
            return false; 
        }

        return true;
    } 

    bool ShaderProgram::BindProgram()
    {
        GLCall(glUseProgram(m_Handle)); 
        return true; 
    }
};