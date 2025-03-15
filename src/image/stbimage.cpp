#include <image/stbimage.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <iostream>

STBImage::STBImage(const std::string& imagePath)
{
    stbi_set_flip_vertically_on_load(true);
    const char *path = imagePath.c_str();
    m_Data = stbi_load(path, &m_Width, &m_Height, &m_Channels, 0);

    if (m_Data == nullptr)
    {
        // FIXME: handle this
    }
}

STBImage::~STBImage()
{
    stbi_image_free(m_Data);
}