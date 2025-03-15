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


    bool ShaderProgram::SetBoolean(const std::string& uniformName, bool b)
    {
        GLint location = GetUniformLocation(uniformName);
        if (location == -1)
            return false;
        glUniform1i(location, b);
        return true;
    }

    bool ShaderProgram::SetInteger(const std::string& uniformName, int i)
    {
        GLint location = GetUniformLocation(uniformName);
        if (location == -1)
            return false;
        glUniform1i(location, i);
        return true;
    }

    bool ShaderProgram::SetFloat(const std::string& uniformName, float f)
    {
        GLint location = GetUniformLocation(uniformName);
        if (location == -1)
            return false;
        glUniform1f(location, f);
        return true;
    }

    bool ShaderProgram::SetVec3f(const std::string& uniformName, const glm::vec3& vec)
    {
        GLint location = GetUniformLocation(uniformName);
        if (location == -1)
            return false;
        glUniform3fv(location, 1, &vec[0]);
        return true;
    }

    bool ShaderProgram::SetVec4f(const std::string& uniformName, const glm::vec4& vec)
    {
        GLint location = GetUniformLocation(uniformName);
        if (location == -1)
            return false;
        glUniform4fv(location, 1, &vec[0]);
        return true;
    }

    bool ShaderProgram::SetMat3f(const std::string& uniformName, const glm::mat3& mat)
    {
        GLint location = GetUniformLocation(uniformName);
        if (location == -1)
            return false;
        glUniformMatrix3fv(location, 1, GL_FALSE, &mat[0][0]);
        return true;
    }

    bool ShaderProgram::SetMat4f(const std::string& uniformName, const glm::mat4& mat)
    {
        GLint location = GetUniformLocation(uniformName);
        if (location == -1)
            return false;
        glUniformMatrix4fv(location, 1, GL_FALSE, &mat[0][0]);
        return true;
    }

    GLint ShaderProgram::GetUniformLocation(const std::string& uniformName)
    {
        const GLchar *name = uniformName.c_str();
        return glGetUniformLocation(m_Handle, name);
    }
};