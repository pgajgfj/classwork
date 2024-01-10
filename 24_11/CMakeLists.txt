cmake_minimum_required(VERSION 3.10)
project(PassportApp)

set(CMAKE_CXX_STANDARD 11)

add_executable(PassportApp Main.cpp Passport.cpp ForeignPassport.cpp)