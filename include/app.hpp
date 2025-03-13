#pragma once

#include <render.hpp>
#include <ref.hpp>
#include <shader.hpp>
#include <window.hpp>

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
        Ref<ZG::Window> m_Window;
        Ref<ZG::ShaderProgram> m_Program; 

};