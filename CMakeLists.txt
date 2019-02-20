cmake_minimum_required(VERSION 2.8.12.2)

project(BOLOS)

add_definitions(-std=c++11)

#add_definitions(-Wall)

set(SRCBOL src/main.cpp )

add_executable(./../bin/BOLOS ${SRCBOL})