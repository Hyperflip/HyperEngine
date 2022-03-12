#pragma once

// define macro for easy import/export of Dll (only under windows)

#ifdef HYPERENGINE_PLATFORM_WINDOWS
	#ifdef HYPERENGINE_BUILD_DLL
		#define HYPERENGINE_API __declspec(dllexport)
	#else
		#define HYPERENGINE_API __declspec(dllimport)
	#endif
#else
	#error HyperEngine only supports Windows!
#endif

#ifdef HE_ENABLE_ASSERTS
	#define HE_ASSERT(x, ...) { if(!(x)) { HE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define HE_CORE_ASSERT(x, ...) { if(!(x)) {HE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define HE_ASSERT(x, ...)
	#define HE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)