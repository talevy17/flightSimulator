cmake_minimum_required(VERSION 3.12)
project(flightSimulator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

include_directories(.)

add_executable(flightSimulator
        Expressions/BinaryExpression.cpp
        Expressions/BinaryExpression.h
        Commands/Command.h
        Expressions/Div.cpp
        Expressions/Div.h
        Expressions/Expression.h
        Interpreter/FlightController.cpp
        Interpreter/FlightController.h
        Interpreter/Lexer.cpp
        Interpreter/Lexer.h
        main.cpp
        Expressions/Minus.cpp
        Expressions/Minus.h
        Expressions/Mult.cpp
        Expressions/Mult.h
        Expressions/Number.cpp
        Expressions/Number.h
        Commands/OpenDataServer.cpp
        Commands/OpenDataServer.h
        Expressions/Plus.cpp
        Expressions/Plus.h
        Interpreter/ShuntingYard.cpp
        Interpreter/ShuntingYard.h Interpreter/FlightController.h Interpreter/Lexer.h Expressions/Bigger.cpp Expressions/Bigger.h Expressions/Smaller.cpp Expressions/Smaller.h Expressions/BiggerEqual.cpp Expressions/BiggerEqual.h Expressions/SmallerEqual.cpp Expressions/SmallerEqual.h Expressions/Var.cpp Expressions/Var.h Data/FlightDataVariables.cpp Data/FlightDataVariables.h Commands/VarCommand.cpp Commands/VarCommand.h Commands/ConditionCommand.cpp Commands/ConditionCommand.h Commands/IfCommand.cpp Commands/IfCommand.h Expressions/NotEqual.cpp Expressions/NotEqual.h Expressions/Equal.cpp Expressions/Equal.h Commands/WhileCommand.cpp Commands/WhileCommand.h Commands/PrintCommand.cpp Commands/PrintCommand.h Expressions/CommandExpression.cpp Expressions/CommandExpression.h Sockets/Server.cpp Sockets/Server.h Commands/ConnectCommand.cpp Commands/ConnectCommand.h Commands/SafeExit.cpp Commands/SafeExit.h Sockets/Client.cpp Sockets/Client.h Commands/SleepCommand.cpp Commands/SleepCommand.h)
