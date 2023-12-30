# CMake Version
cmake_minimum_required(VERSION 3.12)

# Project name
project(ARIA)

set(PROJECT_VERSION "1.0.0-DEV")
set(AUTHOR "Iwaki")

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
    
include_directories(include)
include_directories(${CMAKE_BINARY_DIR})

# Create a executable
add_executable(${EXECUTABLE_NAME} ${SOURCES})