cmake_minimum_required(VERSION 2.6)
project(FakeFramework_1 CXX) # using only C++

add_definitions(-std=c++11 -Wall -Wunused-parameter -Wextra)

file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_library(framework SHARED ${SOURCES})
