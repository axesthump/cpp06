cmake_minimum_required(VERSION 3.17)
project(ex02)

set(CMAKE_CXX_STANDARD 98)

add_executable(ex02 main.cpp Base.cpp Base.hpp A.cpp A.hpp B.cpp B.hpp C.cpp C.hpp)