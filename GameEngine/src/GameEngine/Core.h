#pragma once


#ifdef GE_PLATFORM_WINDOWS

	#ifdef GE_BUILD_DLL
		#define GE_API __declspec(dllexport)
	#else
		#define GE_API __declspec(dllimport)
	#endif

#else
	#error Platform not supported!
#endif

// __debugBreak() : Sets a breakpoint on the stopped line of code. 
#ifdef GE_ENABLE_ASSERTS
	GE_ASSERT(x, ...)		{ if (!x) { GE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugBreak(); } }
	GE_CORE_ASSERT(x, ...)	{ if (!x) { GE_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugBreak(); } }
#else
	#define GE_ASSERT(x, ...)
	#define GE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)