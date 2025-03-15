#pragma once

#include "time.hpp"
#include <camera.hpp>
#include <ref.hpp>

#include <event/callback.hpp>
#include <event/mouse.hpp>
#include <event/window.hpp>

#include <render/render.hpp>
#include <render/shader.hpp>

#include <window/window.hpp>

class Application
{
    public:
        Application(ZG::RenderCore& renderCore) : m_RenderCore(renderCore) {};
        virtual ~Application() = default;

        virtual void RunApp() = 0;

        virtual bool IsInitialized() { return m_Initialized; }
        virtual bool IsRunning() { return m_Running; }

    protected:
        ZG::RenderCore& m_RenderCore; 

        bool m_Initialized = true;
        bool m_Running = true;

};

class GameApplication : public Application
{
    public:
        GameApplication(ZG::RenderCore& renderCore);

        virtual void RunApp() override;
        virtual bool IsRunning() override { return m_Running && m_Window->IsRunning(); }

    protected:
        bool m_Focused = true; 

        Ref<ZG::Window> m_Window;
        Ref<ZG::ShaderProgram> m_Program; 

        Ref<ZG::EventCallback<ZG::WindowSizeEvent>> sizeCallback;
        Ref<ZG::EventCallback<ZG::MouseClickEvent>> clickCallback;
        Ref<ZG::EventCallback<ZG::MouseMoveEvent>> moveCallback;
        Ref<ZG::EventCallback<ZG::WindowFocusEvent>> focusCallback; 

        FPSCamera camera{}; 

        TimedAction focusAction{250}; 

        glm::mat4 m_Perspective;
        glm::mat4 m_View; 

        void CreatePerspective(); 
        void CreatePerspective(float aspect); 

        void PollInputs();

};