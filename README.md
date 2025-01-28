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