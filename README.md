IF NOT VISUAL
conan install . --build missing --output-folder out\build\conan-toolchain
conan install . --output-folder=out\build\conan-toolchain -s build_type=Debug -s compiler.runtime_type=Debug --build=missing
IF VISUAL
conan install . --build missing --output-folder out\build\conan-toolchain -DCMAKE_TOOLCHAIN_FILE="out/build/conan-toolchain/conan_toolchain.cmake"
conan install . --output-folder=out\build\conan-toolchain -s build_type=Debug -s compiler.runtime_type=Debug --build=missing -DCMAKE_TOOLCHAIN_FILE="out/build/conan-toolchain/conan_toolchain.cmake"
