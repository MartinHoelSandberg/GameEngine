#pragma once

#ifdef GE_PLATFORM_WINDOWS

#include "Application.h"

extern GE::Application* GE::createApplication();

int main(int argc, char* argv[])
{
	GE::Log::init();
	GE_CORE_WARN("Initialized Log!");
	int a = 5;
	GE_INFO("Hello! Var={0}", a);

	auto app = GE::createApplication();
	app->run();
	delete app;

	return 0;
}

#endif