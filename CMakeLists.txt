cmake_minimum_required(VERSION 3.25)
project(Bank_Management_System)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Bank_Management_System
        GUI.cpp
        LinkedL.h)
