cmake_minimum_required(VERSION 3.2)

project(Bulk VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost)

include_directories(${Boost_INCLUDE_DIR})

configure_file(version.h.in version.h)

add_executable(bulk main.cpp)

add_library(bulkLib interpreter.cpp commandblock.cpp cout_observer.cpp log_observer.cpp)

set_target_properties(bulk bulkLib PROPERTIES
	CXX_STANDART 14
	CXX_STANDART_REQUIRED ON
	COMPILE_OPTION -Wpedantic -Wall -Wextra
	)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

target_link_libraries(bulk
    bulkLib
)

install(TARGETS bulk RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT ivanbasurman88@yandex.ru)

include(CPack)
