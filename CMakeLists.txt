cmake_minimum_required(VERSION 3.20)
project(4blyat)

set(CMAKE_CXX_STANDARD 17)

add_executable(4blyat main.cpp Firm_info.cpp Firm_info.h Supplier_info.cpp Supplier_info.h Common.cpp Common.h FIO.cpp FIO.h Address.cpp Address.h Date.cpp Date.h StreamTable.h Check.cpp Box.cpp Box.h)
