#pragma once

#include <glad/glad.h>
#include <iostream>

#ifdef NDEBUG

#define GLError()
#define GLCall(F) F

#else

#define GLError() \
do { \
    int err; \
    while ((err = glGetError()) != GL_NO_ERROR) \
    { \
        std::cout << __FILE__ << ":" << __LINE__ << ": error: "; \
        switch (err) \
        { \
            case GL_INVALID_ENUM: std::cout << "GL_INVALID_ENUM" << std::endl; break; \
            case GL_INVALID_VALUE: std::cout << "GL_INVALID_VALUE" << std::endl; break; \
            case GL_INVALID_OPERATION : std::cout << " GL_INVALID_OPERATION " << std::endl; break; \
            case GL_INVALID_FRAMEBUFFER_OPERATION: std::cout << "GL_INVALID_FRAMEBUFFER_OPERATION" << std::endl; break; \
            case GL_OUT_OF_MEMORY: std::cout << "GL_OUT_OF_MEMORY" << std::endl; break; \
            case GL_STACK_UNDERFLOW: std::cout << "GL_STACK_UNDERFLOW" << std::endl; break; \
            case GL_STACK_OVERFLOW: std::cout << "GL_STACK_OVERFLOW" << std::endl; break; \
            default: std::cout << err << std::endl; break; \
        } \
    } \
} while (0)

#define GLCall(F) F; GLError();

#endif