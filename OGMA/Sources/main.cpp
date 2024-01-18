#include "App.hpp"

// #include <curl

#include <cmath>

int main(void)
{
    OGMA::App app;
    if(!app.Initialize())
    {
        return -1;
    }
    while(!app.ShouldQuit())
    {
      app.Update();  
    }
    return 0;
}