cmake_minimum_required(VERSION 3.10)
project(ARTHUR_P C)

# Use C11 standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# ----------- SDL2 CONFIGURATION -----------

# Change this path if your SDL2 is installed elsewhere
set(SDL2_DIR "C:/Libraries/SDL2")

# Include SDL2 headers and your own headers
include_directories(
    "${SDL2_DIR}/include"
    "${CMAKE_SOURCE_DIR}/include"
)

# Link SDL2 libraries folder
link_directories("${SDL2_DIR}/lib")

# ----------- SOURCE FILE COLLECTION -----------

# Collect all .c files in src/ recursively
file(GLOB_RECURSE SRC_FILES "src/*.c")

# Always include main.c in the root
set(SOURCES main.c ${SRC_FILES})

# Optional: collect headers for IDE navigation
file(GLOB_RECURSE HEADER_FILES "include/*.h")

# ----------- EXECUTABLE -----------

# Target name should NOT include paths
add_executable(Arthur ${SOURCES} ${HEADER_FILES})

# Set output directory for executable
set_target_properties(Arthur PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# ----------- LINKING -----------

target_link_libraries(Arthur mingw32 SDL2main SDL2 SDL2_image)