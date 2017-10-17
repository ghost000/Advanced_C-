cmake_minimum_required(VERSION 3.8)
project(vector)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp Vector.cpp)
add_executable(vector ${SOURCE_FILES})

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests main_test.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
