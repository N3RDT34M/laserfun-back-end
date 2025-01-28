find_package(nlohmann_json REQUIRED)
find_package(curlpp REQUIRED)

add_executable (${PROJECT_NAME} "main.cpp")

target_link_libraries(${PROJECT_NAME} nlohmann_json::nlohmann_json)
target_link_libraries(${PROJECT_NAME} curlpp::curlpp)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
endif()

add_subdirectory("Communication")
add_subdirectory("Game")
add_subdirectory("Utils")