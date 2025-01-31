find_package(nlohmann_json REQUIRED)
find_package(beauty REQUIRED)

add_executable(${PROJECT_NAME} "main.cpp")

target_link_libraries(${PROJECT_NAME} nlohmann_json::nlohmann_json)
target_link_libraries(${PROJECT_NAME} beauty::beauty)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)


add_subdirectory("Communication")
add_subdirectory("Game")
add_subdirectory("Utils")

target_link_libraries(${PROJECT_NAME} Communication)
target_link_libraries(${PROJECT_NAME} Game)
target_link_libraries(${PROJECT_NAME} Utils)
