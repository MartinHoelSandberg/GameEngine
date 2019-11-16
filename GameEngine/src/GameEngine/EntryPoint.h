#pragma once

#ifdef GE_PLATFORM_WINDOWS

#include "Application.h"

extern GE::Application* GE::createApplication();

int main(int argc, char* argv[])
{
	GE::Log::init();
	GE_CORE_WARN("Heyoo!");
	GE_INFO("Hola Senor!");
	auto app = GE::createApplication();
	app->run();
	delete app;

	return 0;
}

#endif