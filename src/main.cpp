#include <GLFW/glfw3.h>
#include <iostream>

int main(void)
{
    if (!glfwInit())
    {
        std::cout << "GLFW Failed" << "\n"; 
    }

    std::cout << "End\n";
}