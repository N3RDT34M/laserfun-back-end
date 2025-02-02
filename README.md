# LaserFun - Back end server application

## Installation
This project uses Conan package manager alongside with CMake.

To configure the project, follow these steps:

First, install conan and CMake.
Conan:
```bash
pip install conan --upgrade
```
CMake:
https://cmake.org/download/


If using Visual Studio IDE, run this in Visual Studio Developer PowerShell, else run it from anything.
```bash
conan profile detect --force
```

Then edit the file located in ``C:\Users\antoi\.conan2\profiles\default``:
```
[settings]
arch=x86_64
build_type=Release
compiler=msvc
compiler.cppstd=20
compiler.runtime=dynamic
compiler.version=194
os=Windows
```
Change ``compiler.cppstd`` from ``14`` to ``20``.

### If you're using Visual Studio IDE

```bash
conan install . --build=missing --output-folder=out\build
conan install . --output-folder=out\build -s build_type=Debug -s compiler.runtime_type=Debug --build=missing
```
Every time you change CMake or Conan config, run these commands again.

Open the root folder of the project in Visual Studio (right click > Open in Visual Studio).
As Visual Studio includes a CMake integration, the automatic CMake generation should start.

Edit the ``CMakeSettings.json`` file that appeared in the root directory.
It should look like this:
```json
{
  "configurations": [
    {
      "name": "x64-Debug",
      "generator": "Visual Studio 17 2022 Win64",
      "configurationType": "Debug",
      "inheritEnvironments": [ "msvc_x64_x64" ],
      "buildRoot": "${projectDir}\\out\\build\\${name}",
      "installRoot": "${projectDir}\\out\\install\\${name}",
      "cmakeCommandArgs": "",
      "buildCommandArgs": "",
      "ctestCommandArgs": ""
    }
  ]
}
```
Replace ``Ninja`` by ``Visual Studio 17 2022 Win64``.



### If you're NOT using Visual Studio IDE

```bash
conan install . --build missing --output-folder=out\build\conan-toolchain
conan install . --output-folder=out\build\conan-toolchain -s build_type=Debug -s compiler.runtime_type=Debug --build=missing 
cmake . -DCMAKE_TOOLCHAIN_FILE="out/build/conan-toolchain/conan_toolchain.cmake"
```

### If you're using Linux (or WSL or distant Linux Visual Studio connection)

Let's suppose your conan profile on the host (after detecting it) look like this:

```
Host profile:
[settings]
arch=armv8
build_type=Release
compiler=gcc
compiler.cppstd=gnu17
compiler.libcxx=libstdc++11
compiler.version=12
os=Linux

Build profile:
[settings]
arch=armv8
build_type=Release
compiler=gcc
compiler.cppstd=gnu17
compiler.libcxx=libstdc++11
compiler.version=12
os=Linux
```
After changing the CPP version to 20 by editing the file located in ``~/.conan/profiles/default`` and replacing ``compiler.cppstd=gnu17`` by ``compiler.cppstd=20``.
Then run these commands on the host:

```bash
sudo apt install g++ gdb make ninja-build rsync zip
conan install . --build missing --output-folder=out/build
conan install . --output-folder=out/build -s build_type=Debug --build=missing 
```

IF YOU'RE NOT USING VISUAL STUDIO, you need to specify the toolchain file in the CMake command on the host:
```bash
cmake . -DCMAKE_TOOLCHAIN_FILE="out/build/conan_toolchain.cmake"
```

Here's a preset for a distant configuration (CMakePresets.json):
 ```
{
    "name": "linux-debug",
    "displayName": "Linux Debug",
    "generator": "Ninja",
    "binaryDir": "${sourceDir}/out/build/build/Debug",
    "installDir": "${sourceDir}/out/install/${presetName}",
    "cacheVariables": {
      "CMAKE_BUILD_TYPE": "Debug",
      "CMAKE_TOOLCHAIN_FILE": "${sourceDir}/out/build/build/Debug/generators/conan_toolchain.cmake"
    },
    "condition": {
        "type": "equals",
        "lhs": "${hostSystemName}",
        "rhs": "Linux"
    },
    "vendor": {
        "microsoft.com/VisualStudioRemoteSettings/CMake/1.0": {
            "sourceDir": "$env{HOME}/$ms{projectDirName}"
        }
    }
},
 ```
Note that we edit a cache variable (CMAKE_TOOLCHAIN_FILE) to match the conan toolchain file location.
So, NEVER regenerate the cache with local Visual, or it will break !
It should always be done with the conan install command on the distant host, and then you can click 'Project > Configure cache'.
From here you will have the possibility to select laser-fun-backend build target.

You'll have to create a new profile on your Windows client matching your host's one, run the conan install command again.