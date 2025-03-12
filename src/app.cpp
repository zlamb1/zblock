#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <app.hpp>
#include "glfw/window.hpp"
#include "gl/glshader.hpp"
#include <iostream>

static const char* vertexShaderCode =
    "#version 460\n"
    "in vec3 vecPos;\n"
    "void main()\n"
    "{\n"
    "    gl_Position = vec4(vecPos.xyz, 1.0);\n"
    "}\n";

static const char* fragmentShaderCode =
    "#version 460\n"
    "out vec4 fragColor;"
    "void main()\n"
    "{\n"
    "    fragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
    "}\n";

GameApplication::GameApplication()
{
    if (!glfwInit())
    {
        std::cout << "GLFW Failed\n"; 
        m_Initialized = false; 
        return; 
    }

    m_Window = CreateRef<GLFW::Window>(); 

    if (!m_Window->IsInitialized())
    {
        std::cout << m_Window->GetInitializeErrorHint(); 
        return; 
    }

    m_Window->SetSize(500, 500);
    m_Window->SetTitle("zblock");
    
    m_Window->MakeContextCurrent(); 
    glfwSwapInterval(1);

    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    
    float data[9] = {
        -0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };

    // hello-world tri
    GLint success; 
    char infoLog[512]; 
    GLuint vao, vbo;
    glGenVertexArrays(1, &vao); 
    glBindVertexArray(vao); 

    glGenBuffers(1, &vbo); 
    glBindBuffer(GL_ARRAY_BUFFER, vbo); 
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

    auto vertexShader = CreateRef<GLShader>(ShaderType::VERTEX); 
    if (!vertexShader->CompileShader(vertexShaderCode))
    {
        std::cout << vertexShader->GetCompileError();
        m_Initialized = false; 
        return;
    }

    auto fragmentShader = CreateRef<GLShader>(ShaderType::FRAGMENT); 
    if (!fragmentShader->CompileShader(fragmentShaderCode))
    {
        std::cout << fragmentShader->GetCompileError();
        m_Initialized = false;
        return;
    }

    m_Program = CreateRef<GLShaderProgram>(); 
    m_Program->AttachShader(vertexShader); 
    m_Program->AttachShader(fragmentShader);
    if (!m_Program->CompileProgram())
    {
        std::cout << m_Program->GetCompileError();
        m_Initialized = false;
        return;
    } 

    glEnableVertexAttribArray(0); 
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
        sizeof(data[0]) * 3, (void*) 0);
    
    glViewport(0, 0, 500, 500);
}

void GameApplication::RunApp()
{
    while (IsRunning())
    {
            glClear(GL_COLOR_BUFFER_BIT);
        m_Program->BindProgram(); 
        glDrawArrays(GL_TRIANGLES, 0, 3);
        m_Window->SwapBuffers(); 
        glfwPollEvents();
    }
}