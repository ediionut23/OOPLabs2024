cmake_minimum_required(VERSION 3.27)
project(lab6sapt7)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab6sapt7 main.cpp
        Car.h
        Wheather.h
        Volvo.h
        Volvo.cpp
        BMW.h
        BMW.cpp
        Seat.h
        Seat.cpp
        Fiat.h
        Fiat.cpp
        RangeRover.h
        RangeRover.cpp
        Circuit.h
        Circuit.cpp
)
