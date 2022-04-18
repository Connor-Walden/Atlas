workspace "Atlas"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Atlas/vendor/GLFW/include"
IncludeDir["GLAD"] = "Atlas/vendor/GLAD/include"
IncludeDir["IMGUI"] = "Atlas/vendor/imgui"
IncludeDir["GLM"] = "Atlas/vendor/GLM"

include "Atlas/vendor/GLFW"
include "Atlas/vendor/GLAD"
include "Atlas/vendor/imgui"

project "Atlas"
    location "Atlas"
    kind "StaticLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "atlaspch.h"
    pchsource "Atlas/src/atlaspch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/GLM/glm/**.hpp",
        "%{prj.name}/vendor/GLM/glm/**.inl",
        "%{prj.name}/vendor/IMGUI/backends/imgui_impl_opengl3.cpp",
        "%{prj.name}/vendor/IMGUI/backends/imgui_impl_glfw.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLAD}",
        "%{IncludeDir.IMGUI}",
        "%{IncludeDir.GLM}"
    }

    links
    {
        "GLAD",
        "GLFW",
        "IMGUI",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "ATLAS_PLATFORM_WINDOWS",
            "ATLAS_BUILD_DLL"
        }

    filter "configurations:Debug"
        defines "ATLAS_DEBUG"
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "ATLAS_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "ATLAS_DIST"
        buildoptions "/MD"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/GLM/glm/**.hpp",
        "%{prj.name}/vendor/GLM/glm/**.inl"
    }

    includedirs
    {
        "Atlas/vendor/spdlog/include",
        "Atlas/src",
        "%{IncludeDir.GLM}"
    }

    links
    {
        "Atlas"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "ATLAS_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "ATLAS_DEBUG"
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "ATLAS_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "ATLAS_DIST"
        buildoptions "/MD"
        optimize "On"