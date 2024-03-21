#pragma once
#include "stdafx.hpp"

namespace OGMA::Core
{
	class Window
	{
	private:
		void* handle;
	public:
		void Create(const char* name, s32_2 size);
		void CleanUp();

		void StartFrame();
		void EndFrame();

		bool ShouldQuit();
		void SetQuit(bool state);

		void* GetHandle();
	};
}