#pragma once

#ifdef PK_PLARFORM_WINDOWS
	#ifdef PK_BUILD_DLL
		#define PEKAN_API __declspec(dllexport)
	#else 
		#define PEKAN_API __declspec(dllimport)
	#endif
#else
	#error Pekan only support Windows!
#endif //PK_PLARFORM_WINDOWS

#define BIT(x) (1 << x)


#ifdef PK_ENABLE_ASSERTS
	#define PK_ASSERT(x, ...) { if(!(x)) { PK_ERROR("Assetrion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define PK_CORE_ASSERT(x, ...) { if(!(x)) { PK_CORE_ERROR("Assetrion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define PK_ASSERT(x, ...)
	#define PK_CORE_ASSERT(x, ...)
#endif // PK_ENABLE_ASSERTS

#define PK_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)