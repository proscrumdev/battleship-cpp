cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(battleship)

include_directories("${PROJECT_SOURCE_DIR}")

add_library(controller Battleship.Ascii/Battleship.Ascii.cpp
                       Battleship.GameController.Lib/Ship.cpp
                       Battleship.GameController.Lib/Position.cpp
                       Battleship.GameController.Lib/Letters.cpp
                       Battleship.GameController.Lib/GameController.cpp)
add_executable(game Battleship.Ascii.Lib/Program.cpp)
target_link_libraries(game controller)

option(NAVY_TESTS "enable tests" OFF)

if(NAVY_TESTS)
    find_package(PkgConfig)
    pkg_check_modules(CppUnit REQUIRED cppunit)
    link_directories(${CppUnit_LIBRARY_DIRS})
    include_directories( ${CppUnit_INCLUDE_DIRS} )
    message(STATUS "CppUnit library status:")
    message(STATUS " version: ${CppUnit_VERSION}")
    message(STATUS " libraries: ${CppUnit_LIBRARY_DIRS}")
    message(STATUS " include path: ${CppUnit_INCLUDE_DIRS}")
    include(CTest)
    enable_testing()
    set(UNIT_TESTS ParsePosition CheckIsHit IsShipValid)
    foreach(UNIT_TEST ${UNIT_TESTS})
        add_executable(test_${UNIT_TEST} tests/TestRunner.cpp tests/${UNIT_TEST}Tests.cpp Battleship.Ascii.Lib/Program.cpp)
        target_link_libraries(test_${UNIT_TEST} controller cppunit)
        add_test(NAME test_${UNIT_TEST} COMMAND test_${UNIT_TEST})
    endforeach()
endif()
