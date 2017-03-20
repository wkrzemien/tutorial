cmake_minimum_required(VERSION 2.6)
project(FakeFramework_1 CXX) # using only C++

add_subdirectory(j-pet-fake-framework)

add_definitions(-std=c++11 -Wall -Wunused-parameter -Wextra)


add_executable(tutorial1 ${CMAKE_CURRENT_SOURCE_DIR}/tutorial1.cpp) 
target_link_libraries(tutorial1 framework)

add_executable(tutorial2 ${CMAKE_CURRENT_SOURCE_DIR}/tutorial2.cpp) 
target_link_libraries(tutorial2 framework)


