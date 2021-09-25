cmake_minimum_required(VERSION 3.10)
# set the project name
project(cppBinarySearchTree)

set(CMAKE_CXX_STANDARD 14)

add_executable(app main.cpp TxtSourceRetriever.cpp LocalTxtListRetriever.cpp Utility.cpp)
