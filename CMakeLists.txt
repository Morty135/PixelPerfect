cmake_minimum_required(VERSION 3.29.3)
project(PixelPerfect VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES "src/*")
file(GLOB HEADERS "headers/*")

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/resources" DESTINATION ".")

add_subdirectory(include/raylib)

add_executable("${CMAKE_PROJECT_NAME}" ${SOURCES} ${HEADERS})

target_include_directories("${CMAKE_PROJECT_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/headers")

target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE raylib)