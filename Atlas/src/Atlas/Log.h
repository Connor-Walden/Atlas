#pragma once

#include "Core.h"
#include <spdlog\spdlog.h>
#include <spdlog\fmt\ostr.h>

namespace Atlas
{
	class ATLAS_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// CORE LOGGING
#define CORE_TRACE(...) ::Atlas::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CORE_INFO(...) ::Atlas::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CORE_WARNING(...) ::Atlas::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CORE_ERROR(...) ::Atlas::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CORE_FATAL(...) ::Atlas::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// CLIENT LOGGING
#define TRACE(...) ::Atlas::Log::GetClientLogger()->trace(__VA_ARGS__)
#define INFO(...) ::Atlas::Log::GetClientLogger()->info(__VA_ARGS__)
#define WARNING(...) ::Atlas::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ERROR(...) ::Atlas::Log::GetClientLogger()->error(__VA_ARGS__)
#define FATAL(...) ::Atlas::Log::GetClientLogger()->fatal(__VA_ARGS__)
