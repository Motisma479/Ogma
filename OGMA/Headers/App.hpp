#pragma once
#include "Core/Window.hpp"

namespace OGMA
{
    class App
    {
    public:
        App();
        ~App();

        bool Initialize(const char* name , s32_2 size);
        void Update();

        bool ShouldQuit();
    private:
        Core::Window window;
        void FrameStart();
        void FrameEnd();

    };
}