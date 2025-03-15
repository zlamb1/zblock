#pragma once

#include <zgl/app.hpp>

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