import subprocess
import platform

class Colors:
    CHOOSE_PLATFORM = "\u001b[34m"
    VS2022 = "\u001b[35m"
    VS2017 = "\u001b[33m"
    MAKEFILE = "\u001b[32m"
    OPTION = "\u001b[36m"
    ERROR = "\u001b[31m"

options = [f"Visual Studio 2022{Colors.VS2017}", f"Visual Studio 2017{Colors.MAKEFILE}", f"Makefile {Colors.OPTION}"]

def choose_platform():
    return "gmake"

selected_option = choose_platform()

if platform.system() == "Windows":
    subprocess.run(f"start vendor/premake/premake5.exe {selected_option}", shell=True)
elif platform.system() == "Linux":
    subprocess.run(f"sudo chmod +x ./vendor/premake/premake5", shell=True)
    subprocess.run(f"./vendor/premake/premake5 {selected_option}", shell=True)
