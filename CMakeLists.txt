cmake_minimum_required(VERSION 3.2)

project(bulk)

find_package(Boost COMPONENTS lexical_cast)

include_directories(${Boost_INCLUDE_DIR})

add_executable(b main.cpp)

add_library(bulkLib commandblock.cpp cout_observer.cpp interpreter.cpp log_observer.cpp)

set_target_properties(b bulkLib PROPERTIES
	CXX_STANDARD 14
	CXX_STANDART_REQUIRED ON
	COMPILE_OPTION -Wpedantic -Wall -Wextra
	)

target_link_libraries(b
    bulkLib
)
