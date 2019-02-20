cmake_minimum_required(VERSION 2.8.12.2)

project(Bowling_Game)

add_definitions(-std=c++11)

#add_definitions(-Wall)

include_directories(include)

set(SRCBOL src/main.cpp src/Quadrant.cpp src/Bowling_Game.cpp)

add_executable(./../bin/Bowling ${SRCBOL})
