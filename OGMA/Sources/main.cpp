#include "App.hpp"

// #include <curl

#include <cmath>

s32 main(void)
{
    OGMA::App app;
    if(!app.Initialize({640, 480}, "Ogma"))
    {
      return -1;
    }
    while(!app.ShouldQuit())
    {
      app.Update();  
    }
    return 0;
}