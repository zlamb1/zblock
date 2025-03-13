#include <glad/glad.h>

#include <gl/texture.hpp>

namespace GL
{
    Texture2D::Texture2D(ZG::TextureType textureType) : ZG::Texture2D(textureType)
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
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
};

