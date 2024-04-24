workspace "Audo"

    architecture "x86_64"

    configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Backend"

    kind "ConsoleApp"
    
    language "C++"
    cppdialect "C++20"

    location "./Audo/%{prj.name}"

    targetdir ("./bin/".. outputdir.. "/%{prj.name}")
    objdir ("./bin-int/".. outputdir.. "/%{prj.name}")

    files { "./Audo/%{prj.name}/src/**.cpp", "./Audo/%{prj.name}/include/**.h", "./Audo/%{prj.name}/include/**.hpp" }

    includedirs { "./vendor/cpphttp/include", "./vendor/jwt-cpp/include", "./vendor/libpq/include", "./vendor/openssl/include", "./vendor/soci/include", "./vendor/cpr/curl/include", "./vendor/cpr/include", "./Audo/%{prj.name}/include"}

    filter "configurations:*"
      libdirs { "./vendor/libpq/lib", "./vendor/openssl/lib" }
      links {
        "libpq",
        "libssl",
        "libcrypto"
      }

    systemversion "latest"

    filter "configurations:Debug"
      defines "AD_DEBUG"
      symbols "On"
      libdirs { "./vendor/soci/lib/debug_libs", "./vendor/cpr/libs/Debug-libs" }
      links {	
        "libsoci_core_4_0",
        "libsoci_empty_4_0",
        "libsoci_postgresql_4_0",
        "libcurl-d_imp",
        "cpr"
      }
    
    
    filter "configurations:Release"
      defines "AD_RELEASE"
      optimize "On"
      libdirs { "./vendor/soci/lib", "./vendor/cpr/libs/Release-libs" }
      links {	
        "libsoci_core_4_0",
        "libsoci_empty_4_0",
        "libsoci_postgresql_4_0",
        "libcurl_imp",
        "cpr"
      }