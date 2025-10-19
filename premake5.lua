workspace "Pekan"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Pekan"
	location "Pekan"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	pchheader "pkpch.h"
	pchsource "Pekan/src/pkpch.cpp"

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PK_PLARFORM_WINDOWS",
			"PK_BUILD_DLL"
		}

		postbuildcommands
		{
			"{MKDIR} ../bin/" .. outputdir .. "/Sandbox",
			--("{COPYFILE} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/")
		}

	filter "configurations:Debug"
		defines "PK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PK_DIST"
		optimize "On"

	filter "system:windows"
		buildoptions {"/utf-8"}


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Pekan/vendor/spdlog/include",
		"Pekan/src"
	}

	links
	{
		"Pekan"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		

		defines
		{
			"PK_PLARFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "PK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PK_DIST"
		optimize "On"

	filter "system:windows"
		buildoptions { "/utf-8" }