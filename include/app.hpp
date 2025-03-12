#pragma once

#include <ref.hpp>
#include <shader.hpp>
#include <window.hpp>

class Application
{
    public:
        Application() = default;
        virtual ~Application() = default;

        virtual void RunApp() = 0;

        virtual bool IsInitialized() { return m_Initialized; }
        virtual bool IsRunning() { return m_Running; }

    protected:
        bool m_Initialized = true;
        bool m_Running = true;

};

class GameApplication : public Application
{
    public:
        GameApplication();

        virtual void RunApp() override;
        virtual bool IsRunning() override { return m_Running && m_Window->IsRunning(); }

    protected:
        Ref<ZG::Window> m_Window;
        Ref<ShaderProgram> m_Program; 

};