file(GLOB_RECURSE COMMUNICATION_SOURCES "*.cpp" "*.h")
add_library(Communication ${COMMUNICATION_SOURCES})
target_include_directories(Communication PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    