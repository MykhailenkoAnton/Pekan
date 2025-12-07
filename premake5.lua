workspace "Pekan"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Includer dirs relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Pekan/vendor/GLFW/include"
IncludeDir["Glad"] = "Pekan/vendor/Glad/include"
IncludeDir["ImGui"] = "Pekan/vendor/imgui"

include "Pekan/vendor/GLFW/"
include "Pekan/vendor/Glad/"
include "Pekan/vendor/imgui/"

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
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"

		defines
		{
			"PK_PLARFORM_WINDOWS",
			"PK_BUILD_DLL",
			"PK_ENABLE_ASSERTS",
			"GLFW_INCLUDE_NONE",
			"IMGUI_IMPL_OPENGL_LOADER_CUSTOM"
		}

	filter "configurations:Debug"
		defines "PK_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "PK_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "PK_DIST"
		runtime "Release"
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
		staticruntime "Off"
		
		defines
		{
			"PK_PLARFORM_WINDOWS",
			"PK_ENABLE_ASSERTS"
		}

		postbuildcommands
		{
			("{COPYFILE} ../bin/" .. outputdir .. "/Pekan/Pekan.dll" .. " ../bin/" .. outputdir .. "/%{prj.name}")
		}


	filter "configurations:Debug"
		defines "PK_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "PK_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "PK_DIST"
		runtime "Release"
		optimize "On"

	filter "system:windows"
		buildoptions { "/utf-8" }