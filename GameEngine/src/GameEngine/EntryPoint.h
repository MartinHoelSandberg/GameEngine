#pragma once

#ifdef GE_PLATFORM_WINDOWS

#include "Application.h"

extern GE::Application* GE::createApplication();

int main(int argc, char* argv[])
{
	auto app = GE::createApplication();
	app->run();
	delete app;

	return 0;
}

#endif