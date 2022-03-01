# Battleship C++
A simple game of Battleship, written in C++. The purpose of this repository is to serve as an entry point into coding exercises and it was especially created for scrum.orgs Applying Professional Scrum for Software Development course (www.scrum.org/apssd). The code in this repository is unfinished by design.

This code can be compiled either by using cmake. It has been tested on Windows 10, macOS Monterey, and on Ubuntu 21.10.

## Build and run locally

Build and run it using cmake:
```bash
mkdir build
cd build
cmake ..
make
./game
```

## Build and run Unit-Tests

### Build and running Unit-Tests without Visual Studio

The tests were created using CppUnit (https://sourceforge.net/projects/cppunit/). These tests can be found in the `tests` folder.

To build and run the unit tests, use these commands:

```bash
mkdir build
cd build
cmake -DNAVY_TESTS=ON ..
make
make test
```
