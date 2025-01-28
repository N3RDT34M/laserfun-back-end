file(GLOB_RECURSE UTILS_SOURCES "*.cpp" "*.h")
add_library(Utils ${UTILS_SOURCES})
target_include_directories(Utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    