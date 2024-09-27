cmake_minimum_required(VERSION 3.28.1)

project(Sandy_the_Worm)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "${CMAKE_SOURCE_DIR}/External/SFML/lib/cmake/SFML")

find_package(SFML 2.6.1 COMPONENTS system window graphics audio REQUIRED)

file(GLOB SOURCES "src/*.cpp")

add_executable(Sandy_the_Worm WIN32 ${SOURCES} resources.rc)

target_link_libraries(Sandy_the_Worm sfml-system sfml-window sfml-graphics sfml-audio)

set(RESOURCE_DIR "${CMAKE_SOURCE_DIR}/src/resources")

add_custom_command(TARGET Sandy_the_Worm POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${RESOURCE_DIR} $<TARGET_FILE_DIR:Sandy_the_Worm>/resources)
