Visual Studio build

[![Build status](https://dev.azure.com/aps-sd-stewards/aps-sd/_apis/build/status/proscrumdev.battleship-cpp-CI)](https://dev.azure.com/aps-sd-stewards/aps-sd/_build/latest?definitionId=18)

Make build

[![Build status](https://dev.azure.com/aps-sd-stewards/aps-sd/_apis/build/status/proscrumdev.battleship-cpp-CI)](https://dev.azure.com/aps-sd-stewards/aps-sd/_build/latest?definitionId=20)

# Battleship C++
A simple game of Battleship, written in C++.

This code can be compiled either by using MAKE or Visual Studio. It has been tested on Windows 10 and on Debian GNU/Linux 10

## Build and run locally

Build and run it using MAKE
```bash
cd MAKE
make
./Battleship.exe
```

## Build and run in a Docker container

You can use a Docker Container as a save environment providing all necessary tools to build and run the Battleship application-

### Run a Docker Container with the gcc image

```bash
cd battleship-cpp
docker build . -t battleship
docker run -it -v ${PWD}:/battleship battleship bash
```

### Build and run in the Docker container

Build and run it using MAKE
```bash
cd /battleship/MAKE
make
./Battleship.exe
```

## Build and run Unit-Tests

### Build and running Unit-Tests using Visual Studio

if you are using Visual Studio, you can use the TestExplorer to run tests. You find the tests in the MSTest format in the folders
- Battleship.Ascii.Tests
- Battleship.GameController.Tests

### Build and running Unit-Tests without Visual Studio

You can als run Unit-Tests without Visual STudio, for example in the Docker Container. They are created using CppUnit (https://sourceforge.net/projects/cppunit/). These tests can be found in the folders
- Battleship.GameController.Tests.CppUnit
- Battleship.Ascii.Tests.CppUnit

To build and run the unit tests, use these commands:

```bash
cd /battleship/MAKE
make TestRunner.exe
./TestRunner.exe
```

