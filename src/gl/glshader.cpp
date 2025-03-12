#include "shader.hpp"
#include <gl/glshader.hpp>

GLShader::GLShader(ShaderType shaderType) : Shader(shaderType)
{
    m_Handle = glCreateShader(GetGLShaderType(shaderType));
}

GLShader::~GLShader()
{
    glDeleteShader(m_Handle);
} 

bool GLShader::CompileShader(const char *shaderCode)
{
    GLint success;

    glShaderSource(m_Handle, 1, &shaderCode, NULL);
    glCompileShader(m_Handle);
    glGetShaderiv(m_Handle, GL_COMPILE_STATUS, &success);

    if (success != GL_TRUE)
    {
        GLchar infoLog[512]; 
        glGetShaderInfoLog(m_Handle, 512, NULL, infoLog);
        m_CompileError = "SHADER::COMPILE::ERROR\n";
        m_CompileError += infoLog;
        return false;
    }

    return true;
}

GLenum GLShader::GetGLShaderType(ShaderType shaderType)
{
    switch (shaderType)
    {
        case VERTEX:
            return GL_VERTEX_SHADER;
        case FRAGMENT:
            return GL_FRAGMENT_SHADER; 
        default:
            return 0;
    }
}

GLShaderProgram::GLShaderProgram()
{
    m_Handle = glCreateProgram(); 
}

GLShaderProgram::~GLShaderProgram()
{
    glDeleteProgram(m_Handle); 
}

bool GLShaderProgram::CompileProgram()
{
    GLint success;

    for (auto shader : m_Shaders)
        glAttachShader(m_Handle, shader->GetHandle()); 

    glLinkProgram(m_Handle);

    glGetProgramiv(m_Handle, GL_LINK_STATUS, &success);

    if(success != GL_TRUE)
    {
        GLchar infoLog[512]; 
        glGetProgramInfoLog(m_Handle, 512, NULL, infoLog);
        m_CompileError = "PROGRAM::COMPILE::ERROR\n";
        m_CompileError += infoLog; 
        return false; 
    }

    return true;
} 

bool GLShaderProgram::BindProgram()
{
    glUseProgram(m_Handle); 
    return true; 
}