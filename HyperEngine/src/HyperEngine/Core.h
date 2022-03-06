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

#define BIT(x) (1 << x)