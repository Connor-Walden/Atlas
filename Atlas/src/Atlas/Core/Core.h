#pragma once

#ifdef ATLAS_PLATFORM_WINDOWS
	#ifdef ATLAS_BUILD_DLL
		#define ATLAS_API __declspec(dllexport)
	#else
		#define ATLAS_API __declspec(dllimport)
	#endif
#else
	#error Atlas only supports windows at the moment...
#endif

#ifdef ATLAS_ENABLE_ASSERTS
	#define ASSERT(x, ...) { if(!(x)) { ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define CORE_ASSERT(x, ...) { if(!(x)) { CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ASSERT(x, ...)
	#define CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define BIND_EVENT_FUNCTION(fn) std::bind(&fn, this, std::placeholders::_1)

#define BUFFER_TYPE_COLOR 0x00004000
#define BUFFER_TYPE_DEPTH 0x00000100