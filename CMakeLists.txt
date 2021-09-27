cmake_minimum_required(VERSION 3.0.0)
project(cppBinarySearchTree VERSION 0.1.0)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

add_definitions("-std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(SOURCES main.cpp LocalTxtListRetriever.cpp TxtSourceRetriever.cpp Utility.cpp)
add_executable(myApp ${SOURCES})
target_link_libraries(myApp ${CONAN_LIBS})
include(CPack)
