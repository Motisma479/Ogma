#pragma once
#include "stdafx.hpp"

namespace OGMA
{
    class App
    {
    public:
        App();
        ~App();

        bool Initialize(s32_2 size, const char* title);
        void Update();

        bool ShouldQuit();
    private:
        void* window;
        bool quit;
        void FrameStart();
        void FrameEnd();

    };
}