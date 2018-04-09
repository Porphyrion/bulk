cmake_minimum_required(VERSION 3.2)

project(Bulk)

find_package(Boost)

include_directories(${Boost_INCLUDE_DIR})

configure_file(version.h.in version.h)

add_executable(bulk main.cpp)

add_library(bulkLib interpreter.cpp commandblock.cpp observers.cpp)

set_target_properties(bulk bulkLib PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
	COMPILE_OPTION -Wpedantic -Wall -Wextra
	)

target_link_libraries(bulk
    bulkLib
)
