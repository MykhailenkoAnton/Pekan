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