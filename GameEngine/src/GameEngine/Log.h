#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace GE
{

	class GE_API Log
	{
		public:
			static void init();

			inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return coreLogger; };
			inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return clientLogger; };


	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};

}

// Log macro API: Client and core
#define GE_TRACE(...) ::GE::Log::getClientLogger()->trace(__VA_ARGS__)
#define GE_INFO(...)  ::GE::Log::getClientLogger()->info(__VA_ARGS__)
#define GE_WARN(...)  ::GE::Log::getClientLogger()->warn(__VA_ARGS__)
#define GE_ERROR(...) ::GE::Log::getClientLogger()->error(__VA_ARGS__)
#define GE_FATAL(...) ::GE::Log::getClientLogger()->fatal(__VA_ARGS__)

#define GE_CORE_TRACE(...) ::GE::Log::getCoreLogger()->trace(__VA_ARGS__)
#define GE_CORE_INFO(...)  ::GE::Log::getCoreLogger()->info(__VA_ARGS__)
#define GE_CORE_WARN(...)  ::GE::Log::getCoreLogger()->warn(__VA_ARGS__)
#define GE_CORE_ERROR(...) ::GE::Log::getCoreLogger()->error(__VA_ARGS__)
#define GE_CORE_FATAL(...) ::GE::Log::getCoreLogger()->fatal(__VA_ARGS__)