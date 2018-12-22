cmake_minimum_required(VERSION 3.12)
project(flightSimulator)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(flightSimulator
        BinaryExpression.cpp
        BinaryExpression.h
        Command.h
        Div.cpp
        Div.h
        Expression.h
        FlightController.cpp
        FlightController.h
        Lexer.cpp
        Lexer.h
        main.cpp
        Minus.cpp
        Minus.h
        Mult.cpp
        Mult.h
        Number.cpp
        Number.h
        OpenDataServer.cpp
        OpenDataServer.h
        Plus.cpp
        Plus.h
        ShuntingYard.cpp
        ShuntingYard.h FlightController.h Lexer.h Bigger.cpp Bigger.h Smaller.cpp Smaller.h BiggerEqual.cpp BiggerEqual.h SmallerEqual.cpp SmallerEqual.h Var.cpp Var.h FlightDataVariables.cpp FlightDataVariables.h VarCommand.cpp VarCommand.h ConditionCommand.cpp ConditionCommand.h IfCommand.cpp IfCommand.h NotEqual.cpp NotEqual.h Equal.cpp Equal.h WhileCommand.cpp WhileCommand.h PrintCommand.cpp PrintCommand.h CommandExpression.cpp CommandExpression.h)
