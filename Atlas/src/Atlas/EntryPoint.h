#pragma once

#include "Application.h"

#ifdef ATLAS_PLATFORM_WINDOWS

extern Atlas::Application* Atlas::CreateApplication();

int main(int argc, char** argv)
{
	Atlas::Log::Init();
	CORE_INFO("Initialized Log!");

	auto app = Atlas::CreateApplication();
	app->Run();
	delete app;
}

#endif