cmake_minimum_required(VERSION 3.2)

project(bulk)

find_package(Boost)

include_directories(${Boost_INCLUDE_DIR})

add_executable(b main.cpp)

add_library(cl commadline.cpp)

add_library(ob observer.cpp)

set_target_properties(b cl ob PROPERTIES
	CXX_STANDART 14
	CXX_STANDART_REQUIRED ON
	COMPILE_OPTION -Wpedantic -Wall -Wextra
	)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

target_link_libraries(b
    commadline
)
