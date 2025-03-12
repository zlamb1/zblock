#include <app.hpp>

int main(void)
{
    GameApplication app;
    if (!app.IsInitialized())
        return -1;
    app.RunApp();
    return 0; 
}