
cmake_minimum_required(VERSION 3.24)

project(MatForge
        VERSION 0.1.0
        DESCRIPTION "A C++ linear algebra library"
        LANGUAGES CXX
)

# C++ configuration
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Library
add_library(matforge
        src/matrix.cpp
        include/matforge/matrix.hpp
        include/matforge/matrixop.hpp
        src/matrixop.cpp
)

target_include_directories(matforge
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Demo executable
add_executable(matforge_demo
        src/main.cpp
)





target_link_libraries(matforge_demo
        PRIVATE matforge
)

# Testing
include(CTest)

if(BUILD_TESTING)
    include(FetchContent)

    FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG v1.16.0
    )

    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    FetchContent_MakeAvailable(googletest)

    add_executable(matforge_tests
            tests/matrix_tests.cpp
    )

    target_link_libraries(matforge_tests
            PRIVATE
            matforge
            GTest::gtest_main
    )

    include(GoogleTest)
    gtest_discover_tests(matforge_tests)
endif()
