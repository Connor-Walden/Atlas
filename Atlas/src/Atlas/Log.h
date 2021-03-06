#pragma once

#include "Core\Core.h"
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
#define LOG_CORE_TRACE(...) ::Atlas::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LOG_CORE_INFO(...) ::Atlas::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_CORE_WARNING(...) ::Atlas::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_CORE_ERROR(...) ::Atlas::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LOG_CORE_FATAL(...) ::Atlas::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// CLIENT LOGGING
#define LOG_TRACE(...) ::Atlas::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...) ::Atlas::Log::GetClientLogger()->info(__VA_ARGS__)
#define LOG_WARNING(...) ::Atlas::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...) ::Atlas::Log::GetClientLogger()->error(__VA_ARGS__)
#define LOG_FATAL(...) ::Atlas::Log::GetClientLogger()->fatal(__VA_ARGS__)
