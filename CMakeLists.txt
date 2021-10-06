cmake_minimum_required(VERSION 3.0.0)
project(cppBinarySearchTree VERSION 0.1.0)


include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_FLAGS_RELEASE "-Ofast")

add_definitions("-std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB SOURCES src/*.cpp)

add_executable(myApp ${SOURCES})
target_link_libraries(myApp ${CONAN_LIBS})
include(CPack)
