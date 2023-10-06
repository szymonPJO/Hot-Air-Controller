cmake_minimum_required(VERSION 3.12)
project(${PROJECT_NAME})

set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/PROJECT)

set(LIB_INCLUDE_DIRECTORIES /usr/avr/include)


set(EXECUTABLE ${PROJECT_NAME})
add_executable(${CMAKE_PROJECT_NAME} PROJECT/main.c)
target_include_directories(${EXECUTABLE} PRIVATE
    ${LIB_INCLUDE_DIRECTORIES})
