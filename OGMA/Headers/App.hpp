#pragma once

namespace OGMA
{
    class App
    {
    public:
        App();
        ~App();

        bool Initialize();
        void Update();

        bool ShouldQuit();
    private:
        void* window;
        bool quit;
        void FrameStart();
        void FrameEnd();

    };
}