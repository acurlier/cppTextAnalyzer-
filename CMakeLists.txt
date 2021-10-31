cmake_minimum_required(VERSION 3.0.0)
project(cppBinarySearchTree VERSION 0.1.0)


include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

# set(CMAKE_CXX_FLAGS_RELEASE "-Ofast")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB SOURCES src/*.cpp)

add_executable(bstIndexing ${SOURCES})
target_link_libraries(bstIndexing ${CONAN_LIBS})
include(CPack)
