workspace "Audo"

    architecture "x86_64"

    configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Audo"

    kind "ConsoleApp"
    
    language "C++"
    cppdialect "C++latest"

    location "./%{prj.name}"

    targetdir ("./bin/".. outputdir.. "/%{prj.name}")
    objdir ("./bin-int/".. outputdir.. "/%{prj.name}")

    files { "./%{prj.name}/src/**.cpp", "./%{prj.name}/src/**.h", "./%{prj.name}/src/**.hpp", "./%{prj.name}/src/**.cppm" }

    includedirs { "./vendor/sfml/include", "./%{prj.name}/src", "./vendor/perlinNoise", "./vendor/rng"}

    filter "configurations:*"
      defines { "SFML_STATIC" }
      libdirs { "./vendor/sfml/lib" }
      links
      {
        "opengl32",
        "freetype",
        "winmm",
        "gdi32",
        "flac",
        "vorbisenc",
        "vorbisfile",
        "vorbis",
        "ogg",
        "ws2_32"
      }
      
    -- postbuildcommands { "{COPY} ../vendor/sfml/lib/**.dll ../bin/".. outputdir.."/%{prj.name}" }

    -- staticruntime "On"

    systemversion "latest"

    filter "configurations:Debug"
      defines "AD_DEBUG"
      symbols "On"
      links
      {	
        "sfml-graphics-s-d",
        "sfml-window-s-d",
        "sfml-system-s-d",
        "sfml-audio-s-d",
        "sfml-network-s-d"
      }
    
    
    filter "configurations:Release"
      defines "AD_RELEASE"
      optimize "On"
      links
      {	
        "sfml-graphics-s",
        "sfml-window-s",
        "sfml-system-s",
        "sfml-audio-s",
        "sfml-network-s"
      }