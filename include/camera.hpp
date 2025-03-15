#pragma once

#include "glm/common.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/trigonometric.hpp"
#include <glm/glm.hpp>

class Camera
{
    public:
        virtual ~Camera() = default;

        virtual glm::mat4 CreateViewMatrix() = 0;

};

class FPSCamera : public Camera
{
    public:
        float GetYaw() const { return m_Rotation[0]; }
        float GetPitch() const { return m_Rotation[1]; }

        void SetYaw(float yaw) { m_Rotation[0] = yaw; }
        void SetPitch(float pitch) 
        { 
            m_Rotation[1] = glm::clamp(pitch, -1.5707f, 1.5707f);
        }

        void MoveByVec(const glm::vec3& vec)
        {
            m_Position += vec; 
        }

        virtual glm::vec3 GetForwardDirection() const
        {
            float yaw = GetYaw(), pitch = GetPitch(); 
            return 
            {
                glm::sin(yaw) * glm::cos(pitch),
                glm::sin(pitch),
                glm::cos(yaw) * glm::cos(pitch)
            };
        }

        virtual glm::vec3 GetHorizontalDirection() const
        {
            float yaw = GetYaw(); 
            return { glm::sin(yaw), 0.0f, glm::cos(yaw) };
        }

        virtual glm::vec3 GetUpDirection() const
        {
            return glm::vec3{ 0.0f, 1.0f, 0.0f };
        }

        virtual glm::vec3 GetRightDirection() const
        {
            return glm::cross(GetForwardDirection(), GetUpDirection()); 
        }

        virtual glm::mat4 CreateViewMatrix()
        {
            return glm::lookAt(m_Position, m_Position + GetForwardDirection(), glm::vec3{ 0.0f, 1.0f, 0.0f });
        }
        
    protected:
        glm::vec3 m_Position;
        glm::vec3 m_Rotation;

};