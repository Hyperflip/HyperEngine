workspace "HyperEngine"
    architecture "x64"
    startproject "Sandbox"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "HyperEngine/vendor/GLFW/include"

include "HyperEngine/vendor/GLFW"

project "HyperEngine"
    location "HyperEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-interm/" .. outputdir .. "/%{prj.name}")

	pchheader "hepch.h"
	pchsource "HyperEngine/src/hepch.cpp"

	staticruntime "off"
	runtime "Release"
	buildoptions {"/MD"}

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
    }

	links {
		"GLFW",
		"opengl32.lib"
	}

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "HYPERENGINE_PLATFORM_WINDOWS",
            "HYPERENGINE_BUILD_DLL"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "HE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "HE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "HE_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-interm/" .. outputdir .. "/%{prj.name}")

	staticruntime "off"
	runtime "Release"
	buildoptions {"/MD"}

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
       "HyperEngine/vendor/spdlog/include",
       "HyperEngine/src"
    }

    links {
        "HyperEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "HYPERENGINE_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "HE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "HE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "HE_DIST"
        optimize "On"