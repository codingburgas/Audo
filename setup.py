import subprocess
import platform

class Colors:
    CHOOSE_PLATFORM = "\u001b"
    VS2022 = "\u001b"
    VS2017 = "\u001b"
    MAKEFILE = "\u001b"
    OPTION = "\u001b"
    ERROR = "\u001b"

options = [f"Visual Studio 2022{Colors.VS2017}", f"Visual Studio 2017{Colors.MAKEFILE}", f"Makefile {Colors.OPTION}"]

def choose_platform():
    option = 1

    print(f"{Colors.CHOOSE_PLATFORM}Choose platform:{Colors.VS2022}")

    for i in options:
        print(f"{option}: {i}")
        option += 1

    print("Enter number:", end=" \u001b")

    try:
        option = input()
    except KeyboardInterrupt:
        print(f"\n{Colors.ERROR}Program force stopped by user")
        exit()
        

    try:
        option = int(option)

        if(option > len(options)):
            try:
                raise Exception()
            except:
                print(f"{Colors.ERROR}Please enter valid number")
                exit()

    except ValueError:
        print(f"{Colors.ERROR}Please enter valid number")
        exit()

    if option == 1:
        return "vs2022"
    elif option == 2:
        return "vs2017"
    elif option == 3:
        return "gmake"

selected_option = choose_platform()

if platform.system() == "Windows":
    subprocess.run(f"start ./vendor/premake/premake5.exe {selected_option}", shell=True)
elif platform.system() == "Linux":
    subprocess.run(f"sudo chmod +x ./vendor/premake/premake5", shell=True)
    subprocess.run(f"./vendor/premake/premake5 {selected_option}", shell=True)
