#pragma once

#include "Application.h"

#ifdef ATLAS_PLATFORM_WINDOWS

extern Atlas::Application* Atlas::CreateApplication();

int main(int argc, char** argv)
{
	Atlas::Log::Init();
	CORE_WARNING("Initialized Log!");
	int a = 5;
	INFO("Hello! Var={0}", a);

	auto app = Atlas::CreateApplication();
	app->Run();
	delete app;
}

#endif