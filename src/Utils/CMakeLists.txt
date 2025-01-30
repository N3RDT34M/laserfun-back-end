file(GLOB UTILS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

add_library(Utils ${UTILS_SOURCES})
target_include_directories(Utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(Utils PUBLIC nlohmann_json::nlohmann_json)