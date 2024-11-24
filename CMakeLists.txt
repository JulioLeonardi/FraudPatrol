cmake_minimum_required(VERSION 3.29)
project(QuickAntiFraud)

set(CMAKE_CXX_STANDARD 20)

add_executable(QuickAntiFraud main.cpp
        TransactionGraph.h
)
