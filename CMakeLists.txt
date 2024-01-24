# CMake Version
cmake_minimum_required(VERSION 3.12)

# Project name
project(ARIA)

set(PROJECT_VERSION "1.0.0-DEV")
set(AUTHOR "Iwaki")

set(OSBitness 32)
if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(OSBitness 64)
endif()

set (FullOutputDir "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}${OSBitness}/${CMAKE_BUILD_TYPE}")
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FullOutputDir}")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FullOutputDir}")

configure_file(config/config.h.in ${CMAKE_BINARY_DIR}/config.h)

# Set the executable name
set(EXECUTABLE_NAME "${PROJECT_NAME}-${PROJECT_VERSION}")

# Language version
set(CMAKE_CXX_STANDARD 17)

# Files to include in compilation
set(SOURCES
    src/main.cpp
    src/aria.cpp
    src/commands/commands.cpp
    src/commands/ls.cpp
    src/commands/go.cpp
    src/commands/del.cpp
    src/commands/info.cpp
    src/commands/help.cpp
    src/commands/create.cpp
    src/integration/discord.cpp
    src/ssh/sshConnection.cpp)
    
# Include directories for the executable
include_directories(include)
include_directories(${CMAKE_BINARY_DIR})

# Create an executable
add_executable(${EXECUTABLE_NAME} ${SOURCES})

add_custom_command(
    TARGET ${EXECUTABLE_NAME}
    POST_BUILD
    COMMAND echo $<TARGET_FILE:${EXECUTABLE_NAME}> > ${CMAKE_BINARY_DIR}/launch_aria.bat
    COMMENT "[BUILD] Successfully created Aria launch script!"
)