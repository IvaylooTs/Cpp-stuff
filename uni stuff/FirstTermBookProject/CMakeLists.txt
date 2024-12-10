cmake_minimum_required(VERSION 3.26)
project(FirstTermBookProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(FirstTermBookProject main.cpp
        Textbook.h
        Order.h
        Distributor.h
        Menu.h)
