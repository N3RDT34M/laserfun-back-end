file(GLOB_RECURSE GAME_SOURCES "*.cpp" "*.h")
add_library(Game ${GAME_SOURCES})
target_include_directories(Game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    