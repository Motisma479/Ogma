#include "App.hpp"

// #include <curl

#include <cmath>

s32 main(void)
{
    OGMA::App app;
    if(!app.Initialize("Ogma", { 640, 480 }))
    {
      return -1;
    }
    while(!app.ShouldQuit())
    {
      app.Update();  
    }
    return 0;
}