#include "gepch.h"
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace GE
{
	std::shared_ptr<spdlog::logger> Log::coreLogger;
	std::shared_ptr<spdlog::logger> Log::clientLogger;

	void Log::init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		clientLogger = spdlog::stdout_color_mt("Sandbox");
		clientLogger->set_level(spdlog::level::trace);

		coreLogger = spdlog::stdout_color_mt("GameEngine");
		coreLogger->set_level(spdlog::level::trace);
	}
}