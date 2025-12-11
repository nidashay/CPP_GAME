cmake_minimum_required(VERSION 3.10)
project(ARTHUR_P)

# Use modern C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ----------- SDL2 CONFIGURATION -----------

# Change this path if your SDL2 is installed elsewhere
set(SDL2_DIR "C:/MinGW")

# Include SDL2 headers
include_directories("${SDL2_DIR}/include/SDL2" "include")

# Link SDL2 libraries
link_directories("${SDL2_DIR}/lib")

# ----------- SOURCE FILE COLLECTION -----------

# Collect all .cpp files in src/ recursively
file(GLOB_RECURSE SRC_FILES "src/*.cpp")

# Always include main.cpp in the root
set(SOURCES main.cpp ${SRC_FILES})

# Collect all headers (optional, just for IDE navigation)
file(GLOB_RECURSE HEADER_FILES "include/*.h")

# ----------- EXECUTABLE -----------

add_executable(Arthur ${SOURCES} ${HEADER_FILES})

# ----------- LINKING -----------

target_link_libraries(Arthur mingw32 SDL2main SDL2 SDL2_image)


