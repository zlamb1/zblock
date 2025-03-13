#include <glfw/render.hpp>
#include <app.hpp>

int main(void)
{
    GLFW::GLRenderCore renderCore;
    GameApplication app{renderCore};
    if (!app.IsInitialized())
        return -1;
    app.RunApp();
    return 0; 
}