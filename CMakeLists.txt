cmake_minimum_required(VERSION 3.13)
project(flightSimulator)

set(CMAKE_CXX_STANDARD 14)

add_executable(flightSimulator main.cpp Expression.h BinaryExpression.cpp BinaryExpression.h Number.cpp Number.h Plus.cpp Plus.h Minus.cpp Minus.h Div.cpp Div.h Mult.cpp Mult.h ShuntingYard.cpp ShuntingYard.h)