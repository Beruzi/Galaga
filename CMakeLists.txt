# Specify the minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Galaga)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories for headers
include_directories(
    ${CMAKE_SOURCE_DIR}/include          # Base include directory
    ${CMAKE_SOURCE_DIR}/include/entities # Include for entity headers
    ${CMAKE_SOURCE_DIR}/include/managers # Include for manager headers
)

# Find SDL2 package
find_package(SDL2 REQUIRED)

# Include SDL2 directories
include_directories(${SDL2_INCLUDE_DIRS})

# Find all source files
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Add the executable target
add_executable(Galaga ${SOURCES})

# Link SDL2 library
target_link_libraries(Galaga ${SDL2_LIBRARIES})
