cmake_minimum_required(VERSION 3.10)
project(Battleship)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -O0")

# Define the paths
set(CPPUNIT_PATH /usr/local/lib)
set(BATTLESHIP_LIB_INCLUDE_PATH ${CMAKE_SOURCE_DIR}/Battleship.Ascii.Lib)
set(GAMECONTROLLER_INCLUDE_PATH ${CMAKE_SOURCE_DIR}/Battleship.GameController.Lib)

# Include directories
include_directories(${CPPUNIT_PATH})
include_directories(${BATTLESHIP_LIB_INCLUDE_PATH})
include_directories(${GAMECONTROLLER_INCLUDE_PATH}) 

# Add the executable for the main target
add_executable(Battleship
    ../Battleship.Ascii/Battleship.Ascii.cpp
    ../Battleship.Ascii.Lib/Program.cpp
    ../Battleship.GameController.Lib/Ship.cpp
    ../Battleship.GameController.Lib/Position.cpp
    ../Battleship.GameController.Lib/Letters.cpp
    ../Battleship.GameController.Lib/GameController.cpp
)

# Add the libraries
add_library(Program STATIC ../Battleship.Ascii.Lib/Program.cpp)
add_library(GameController STATIC
    ../Battleship.GameController.Lib/Ship.cpp
    ../Battleship.GameController.Lib/Position.cpp
    ../Battleship.GameController.Lib/Letters.cpp
    ../Battleship.GameController.Lib/GameController.cpp
)

# Link the libraries to the main target
target_link_libraries(Battleship Program GameController)

# Find and include Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add the executable for the tests
add_executable(TestRunner
    ../Battleship.GameController.Tests/CheckIsHitTests.cpp
    ../Battleship.GameController.Tests/IsShipValidTests.cpp
    ../Battleship.Ascii.Tests/ParsePositionTests.cpp
    ../Battleship.GameController.Tests/TestRunner.cpp
)

# Link the libraries and Google Test to the test runner
target_link_libraries(TestRunner
    Program
    GameController
    ${GTEST_LIBRARIES}
    ${GTEST_MAIN_LIBRARIES}
    pthread
)

# Enable testing and add the test
enable_testing()

# Add the test executable to CTest
add_test(NAME AllTests COMMAND TestRunner --gtest_color=yes)