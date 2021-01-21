cmake_minimum_required(VERSION 3.17)
project(Operation_of_large_integers)

set(CMAKE_CXX_STANDARD 14)

add_executable(Operation_of_large_integers Node.h LinkList.h LinkList.cpp BigInteger.h BigInteger.cpp main.cpp Action.h Action.cpp)