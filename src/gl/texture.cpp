#include <glad/glad.h>

#include <gl/texture.hpp>

namespace GL
{
    Texture2D::Texture2D() : ZG::Texture2D()
    {
        glGenTextures(1, &m_Handle);
    }

    Texture2D::~Texture2D()
    {
        glDeleteTextures(1, &m_Handle);
    }

    bool Texture2D::BindTexture()
    {
        glBindTexture(GL_TEXTURE_2D, m_Handle); 
        return true;
    }

    void Texture2D::SetImage(int width, int height, unsigned char *data)
    {
        BindTexture();

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
};

