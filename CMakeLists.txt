cmake_minimum_required(VERSION 2.8.11)
project(interval)

include_directories(Integer Rational Real)
add_executable(interval main.cpp
        Integer/Integer.hpp Integer/Integer.cpp
        Rational/Rational.hpp Rational/Rational.cpp
        Real/Real.hpp Real/Real.cpp)