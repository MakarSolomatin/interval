cmake_minimum_required(VERSION 2.8.11)
project(interval)

add_executable(interval main.cpp rational/Rational.cpp rational/Rational.h rational/integer/Integer.cpp rational/integer/Integer.h)