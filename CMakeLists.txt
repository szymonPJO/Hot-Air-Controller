cmake_minimum_required(VERSION 3.12)

# set(MCU atmega32)
# set(F_CPU 8000000UL)
set(CMAKE_PROJECT_NAME ${MY_PROJECT_NAME})

# COMPILLER #1
set(TOOLCHAIN_PREFIX avr-)
set(CMAKE_C_COMPILER ${TOOLCHAIN_PREFIX}gcc)
set(CMAKE_ASM_COMPILER ${CMAKE_C_COMPILER})
# set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}g++ ${FLAGS} ${CPP_FLAGS})
set(CMAKE_OBJCOPY ${TOOLCHAIN_PREFIX}objcopy)
set(CMAKE_SIZE ${TOOLCHAIN_PREFIX}size)
set(CMAKE_C_FLAGS ${FLAGS})
set(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/PROJECT)

set(CPU_PARAMETERS
-mmcu=${MCU} 
-DF_CPU=${F_CPU})
project(${CMAKE_PROJECT_NAME})

######### COMPILLER #2 #########
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR avr)

# Some default GCC settings
set(FLAGS
"-fdata-sections -ffunction-sections \
 -Wl,--gc-sections")
# set(CPP_FLAGS
#     "-fno-rtti -fno-exceptions \
#     -fno-threadsafe-statics")

set(CMAKE_EXECUTABLE_SUFFIX_C ".elf")
set(CMAKE_EXECUTABLE_SUFFIX_ASM ".elf")
# set(CMAKE_EXECUTABLE_SUFFIX_CXX ".elf")

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
######### ######### ######### 

set(EXECUTABLE ${CMAKE_PROJECT_NAME})
enable_language(C ASM) #CXX#
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)
# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS ON)

# Headers
set(MY_INCLUDE_DIRECTORIES /usr/avr/include)
set(PROJECT_INCLUDE_DIRECTORIES ${PROJECT_DIR})

# Sources
# file(GLOB_RECURSE MY_INCLUDE_SOURCES
#     )
file(GLOB_RECURSE PROJECT_SOURCES FOLLOW_SYMLINKS
    # ${PROJECT_DIR}/*.cpp
    ${PROJECT_DIR}/*.c)

# Executable files
add_executable(${EXECUTABLE}
    # ${MY_INCLUDE_SOURCES} 
    ${PROJECT_SOURCES})

# Embedded macros(defines)
target_compile_definitions(${EXECUTABLE} PRIVATE
    ${MCU})

target_include_directories(${EXECUTABLE} PRIVATE
    ${MY_INCLUDE_DIRECTORIES}
    ${PROJECT_INCLUDE_DIRECTORIES})

# Compiler and linker options
target_compile_options(${EXECUTABLE} PRIVATE
    ${CPU_PARAMETERS}
    # -g
    -Wall
    -Wextra
    # -Wpedantic
    -Wno-unused-parameter
    # $<$<COMPILE_LANGUAGE:CXX>:
    #     -Wno-volatile
    #     -Wold-style-cast
    #     -Wuseless-cast
    #     -Wsuggest-override>
    # $<$<CONFIG:Debug>:-ggdb>
    $<$<CONFIG:Debug>:-Og -O0>
    $<$<CONFIG:Release>:-Og -g3 -Os>)

target_link_options(${EXECUTABLE} PRIVATE
    ${CPU_PARAMETERS}
    -Wl,-Map=${CMAKE_PROJECT_NAME}.map
    -Wl,--start-group
    -lc
    -lm
    # -lstdc++
    # -lsupc++
    -Wl,--end-group
    -Wl,--print-memory-usage)

add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${EXECUTABLE}>)

add_custom_command(TARGET ${EXECUTABLE} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${EXECUTABLE}>
    ${EXECUTABLE}.hex
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${EXECUTABLE}>
    ${EXECUTABLE}.bin)
