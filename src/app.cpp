#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <app.hpp>
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

GameApplication::GameApplication(ZG::RenderCore& renderCore) : Application(renderCore)
{
    if (!m_RenderCore.InitializeCore())
    {
        std::cout << m_RenderCore.GetInitializeError(); 
        return;
    }

    m_Window = m_RenderCore.CreateWindow(500, 500); 

    if (!m_Window->IsInitialized())
    {
        std::cout << m_Window->GetInitializeErrorHint(); 
        return; 
    }
    
    m_Window->SetTitle("zblock");
    
    // make window context current for thread
    if (!m_RenderCore.MakeContextCurrent(m_Window))
    {
        std::cout << "MakeContextCurrent\n"; 
        return;
    }

    // enable v-sync
    m_RenderCore.SetSwapInterval(1);
    
    float data[9] = {
        -0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };

    // hello-world tri
    GLuint vao, vbo;
    glGenVertexArrays(1, &vao); 
    glBindVertexArray(vao); 

    glGenBuffers(1, &vbo); 
    glBindBuffer(GL_ARRAY_BUFFER, vbo); 
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
    
    auto vertexShader = m_RenderCore.CreateShader(ShaderType::VERTEX); 
    if (!vertexShader->CompileShader(vertexShaderCode))
    {
        std::cout << vertexShader->GetCompileError();
        m_Initialized = false; 
        return;
    }

    auto fragmentShader = m_RenderCore.CreateShader(ShaderType::FRAGMENT); 
    if (!fragmentShader->CompileShader(fragmentShaderCode))
    {
        std::cout << fragmentShader->GetCompileError();
        m_Initialized = false;
        return;
    }

    m_Program = m_RenderCore.CreateProgram(); 
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

    m_RenderCore.SetViewport(0, 0, 500, 500);
}

void GameApplication::RunApp()
{
    while (IsRunning())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        m_Program->BindProgram(); 
        glDrawArrays(GL_TRIANGLES, 0, 3);
        m_Window->SwapBuffers(); 
        m_Window->PollEvents();
    }
}