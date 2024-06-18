cmake_minimum_required(VERSION 3.15)
project(backend)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include Conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Add source files
set(SOURCES
    src/main.cpp
    src/compile_run.cpp
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link Crow library
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})
