file(GLOB COMMUNICATION_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
add_library(Communication ${COMMUNICATION_SOURCES})
target_include_directories(Communication PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(Communication PUBLIC
Utils
nlohmann_json::nlohmann_json
beauty::beauty)

if(UNIX AND NOT APPLE)
  target_link_libraries(Communication PUBLIC /usr/arm-linux-gnueabihf/lib/librf24.so)
endif()