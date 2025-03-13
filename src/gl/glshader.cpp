#include <shader.hpp>

#include <gl/debug.hpp>
#include <gl/glshader.hpp>

GLShader::GLShader(ShaderType shaderType) : Shader(shaderType)
{
    m_Handle = GLCall(glCreateShader(GetGLShaderType(shaderType)));
}

GLShader::~GLShader()
{
    glDeleteShader(m_Handle);
} 

bool GLShader::CompileShader(const char *shaderCode)
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
    m_Handle = GLCall(glCreateProgram()); 
}

GLShaderProgram::~GLShaderProgram()
{
    glDeleteProgram(m_Handle); 
}

bool GLShaderProgram::CompileProgram()
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

bool GLShaderProgram::BindProgram()
{
    GLCall(glUseProgram(m_Handle)); 
    return true; 
}