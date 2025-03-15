#include "event/mouse.hpp"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/geometric.hpp"
#include "glm/trigonometric.hpp"
#include "window/kb.hpp"
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <app.hpp>

#include <event/callback.hpp>
#include <event/window.hpp>

static const char* vertexShaderCode =
    "#version 460\n"
    "uniform mat4 mPerspective;"
    "uniform mat4 mView;"
    "in vec3 vPos;\n"
    "void main()\n"
    "{\n"
    "    gl_Position = mPerspective * mView * vec4(vPos.xyz, 1.0);\n"
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
    m_Window->HideCursor();

    // make window context current for thread
    if (!m_RenderCore.MakeContextCurrent(m_Window))
    {
        std::cout << "MakeContextCurrent\n"; 
        return;
    }

    sizeCallback = CreateRef<ZG::EventCallback<ZG::WindowSizeEvent>>([&](auto event) 
    {
        CreatePerspective((float) event->GetWidth() / (float) event->GetHeight()); 
        m_RenderCore.SetViewport(0, 0, event->GetWidth(), event->GetHeight());
    });

    focusCallback = CreateRef<ZG::EventCallback<ZG::WindowFocusEvent>>([&](auto event)
    {
        if (event->IsWindowFocused())
        {
            int halfWidth = m_Window->GetWidth() / 2, halfHeight = m_Window->GetHeight() / 2;
            m_Window->SetMousePosition(halfWidth, halfHeight);
        }
    });

    moveCallback = CreateRef<ZG::EventCallback<ZG::MouseMoveEvent>>([&](auto event)
    {
        if (event->IsWindowFocused())
        {
            int halfWidth = m_Window->GetWidth() / 2, halfHeight = m_Window->GetHeight() / 2;
            
            constexpr float cameraSpeed = 0.002f;
            float dx = halfWidth - event->GetX(), dy = halfHeight - event->GetY();
            camera.SetYaw(camera.GetYaw() + dx * cameraSpeed);
            camera.SetPitch(camera.GetPitch() + dy * cameraSpeed);
            m_View = camera.CreateViewMatrix(); 

            m_Window->SetMousePosition(halfWidth, halfHeight);
        }
    });

    m_Window->SubscribeEvent<ZG::WindowSizeEvent>(sizeCallback);
    m_Window->SubscribeEvent<ZG::MouseMoveEvent>(moveCallback);

    // enable v-sync
    m_RenderCore.SetSwapInterval(1);
    
    float data[9] = 
    {
        -0.5f, -0.5f, 3.0f,
        0.0f, 0.5f, 3.0f,
        0.5f, -0.5f, 3.0f
    };

    // hello-world tri
    GLuint vao, vbo;
    glGenVertexArrays(1, &vao); 
    glBindVertexArray(vao); 

    glGenBuffers(1, &vbo); 
    glBindBuffer(GL_ARRAY_BUFFER, vbo); 
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
    
    auto vertexShader = m_RenderCore.CreateShader(ZG::ShaderType::VERTEX); 
    if (!vertexShader->CompileShader(vertexShaderCode))
    {
        std::cout << vertexShader->GetCompileError();
        m_Initialized = false; 
        return;
    }

    auto fragmentShader = m_RenderCore.CreateShader(ZG::ShaderType::FRAGMENT); 
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
    CreatePerspective();
    m_View = camera.CreateViewMatrix(); 

    while (IsRunning())
    {
        PollInputs();
        glClear(GL_COLOR_BUFFER_BIT);

        m_Program->BindProgram(); 
        m_Program->SetMat4f("mPerspective", m_Perspective);
        m_Program->SetMat4f("mView", m_View);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        m_Window->SwapBuffers(); 
        m_Window->PollEvents();
    }
}

void GameApplication::CreatePerspective()
{
    CreatePerspective((float) m_Window->GetWidth() / (float) m_Window->GetHeight());
}

void GameApplication::CreatePerspective(float aspect)
{
    m_Perspective = glm::perspective(glm::radians(45.0f), aspect, 0.1f, 100.0f);
}

void GameApplication::PollInputs()
{
    float movementSpeed = 0.02f; 
    glm::vec3 movementVec{0.0f};

    glm::vec3 forwardDir = camera.GetHorizontalDirection(); 
    forwardDir.y = 0; 
    const glm::vec3 upDir = camera.GetUpDirection(); 
    const glm::vec3 rightDir = glm::cross(forwardDir, upDir); 

    if (m_Window->IsKeyPressed(ZG::KeyCode::W))
        movementVec += forwardDir; 
    if (m_Window->IsKeyPressed(ZG::KeyCode::S))
        movementVec -= forwardDir; 
    if (m_Window->IsKeyPressed(ZG::KeyCode::D))
        movementVec += rightDir;
    if (m_Window->IsKeyPressed(ZG::KeyCode::A))
        movementVec -= rightDir;
    if (m_Window->IsKeyPressed(ZG::KeyCode::SPACE))
        movementVec += upDir;
    if (m_Window->IsKeyPressed(ZG::KeyCode::LEFT_CONTROL))
        movementVec -= upDir; 
    if (m_Window->IsKeyPressed(ZG::KeyCode::LEFT_SHIFT))
        movementSpeed *= 3; 

    if (forwardDir.length())
    {
        camera.MoveByVec(movementVec * movementSpeed); 
        m_View = camera.CreateViewMatrix(); 
    }
}