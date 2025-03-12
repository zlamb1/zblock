#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <iostream>

static const char* vertShaderText =
    "#version 460\n"
    "in vec3 vecPos;\n"
    "void main()\n"
    "{\n"
    "    gl_Position = vec4(vecPos.xyz, 1.0);\n"
    "}\n";

static const char* fragShaderText =
    "#version 460\n"
    "out vec4 fragColor;"
    "void main()\n"
    "{\n"
    "    fragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
    "}\n";

int main(void)
{
    if (!glfwInit())
    {
        std::cout << "GLFW Failed\n"; 
        return -1; 
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 

    GLFWwindow* window = 
        glfwCreateWindow(640, 480, "zblock", NULL, NULL);

    if (window == nullptr)
    {
        std::cout << "GLFW Failed - Window NULL\n"; 
        return -1; 
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    
    float data[9] = {
        -0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };

    // hello-world tri
    GLint success; 
    char infoLog[512]; 
    GLuint vao, vbo, vertShader, fragShader, program;
    glGenVertexArrays(1, &vao); 
    glBindVertexArray(vao); 

    glGenBuffers(1, &vbo); 
    glBindBuffer(GL_ARRAY_BUFFER, vbo); 
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

    vertShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertShader, 1, &vertShaderText, NULL);
    glCompileShader(vertShader);
    glGetShaderiv(vertShader, GL_COMPILE_STATUS, &success);
    if (success != GL_TRUE)
    {
        glGetShaderInfoLog(vertShader, 512, NULL, infoLog);
        std::cout << "VERTEX::SHADER::COMPILATION\n" << infoLog << std::endl; 
        return -1;
    }
    fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &fragShaderText, NULL);
    glCompileShader(fragShader);
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
    if (success != GL_TRUE)
    {
        glGetShaderInfoLog(fragShader, 512, NULL, infoLog);
        std::cout << "FRAGMENT::SHADER::COMPILATION\n" << infoLog << std::endl; 
        return -1;
    }

    program = glCreateProgram();
    glAttachShader(program, vertShader);
    glAttachShader(program, fragShader);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(success != GL_TRUE)
    {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM\n" << infoLog << std::endl;
    }

    glEnableVertexAttribArray(0); 
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
        sizeof(data[0]) * 3, (void*) 0);
    
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(program);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window); 
        glfwPollEvents();
    }

    glfwDestroyWindow(window); 
    glfwTerminate();
    return 0; 
}