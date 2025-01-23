cmake_minimum_required(VERSION 3.23)


add_executable(laserfun-back-end "main.cpp")
target_compile_features(laserfun-back-end PRIVATE cxx_std_20)


include(InstallRequiredSystemLibraries)
install(TARGETS laserfun-back-end)

