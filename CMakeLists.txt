cmake_minimum_required(VERSION 2.8)
project(z1_18)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable(zhozhozho main.cpp Tokenaizer.cpp CList.cpp LNode.cpp Autotest.cpp Tokenaizer.h Token.h CList.h LNode.h)
