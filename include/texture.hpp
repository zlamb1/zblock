#pragma once

#include "resource.hpp"

namespace ZG
{
    enum TextureType
    {
        TEXTURE_2D,
        TEXTURE_3D
    };

    class Texture : public ResourceHandle<uint> 
    {
        public:
            Texture(TextureType textureType) : m_TextureType(textureType) {}
            virtual ~Texture() = default; 

            virtual bool BindTexture() = 0;

            TextureType GetTextureType() const { return m_TextureType; }

        protected:
            TextureType m_TextureType; 

    };

    class Texture2D : public Texture
    {
        public:
            Texture2D(TextureType textureType) : Texture(textureType) {}
            virtual ~Texture2D() = default; 

            virtual void SetImage(int width, int height, unsigned char *data) = 0; 
    };
};