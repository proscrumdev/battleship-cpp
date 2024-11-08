![Build status](https://dev.azure.com/APS-SD-Stewards/APS-SD/_apis/build/status/proscrumdev.battleship-cpp-CI)

# Battleship C++
A simple game of Battleship, written in C++.

This code can be compiled by using MAKE. It has been tested on Ubuntu 20.04 and Debian GNU/Linux 10

## Build and run with a DevContainer (Recommended)

The recommended way to develop, build and test the application is by using DevContainers. DevContainers are a feature of Visual Studio Code that allow you to define a development environment in a Docker container. This ensures that all developers have the same development environment and dependencies.

To use DevContainers, you need to have Visual Studio Code installed. You can download it from https://code.visualstudio.com/
And you need to have Docker installed. You can download it from https://www.docker.com/

### Open the project in Visual Studio Code

1. Clone the repository
2. Open Visual Studio Code
3. Click on the "Open Folder" button
4. Select the folder where you cloned the repository
5. Click on the "Reopen in Container" button in the bottom right corner

Now you run your development environment in a Docker container. The first time you open the project in a DevContainer, it will take a few minutes to build the container. After that, the container will be reused and the startup time will be much faster.

All settings in Visual Studio Code are stored in the .devcontainer folder and should get you started with the development quickly. 
- To build and run the application, you can just press \<Ctrl>+\<Shift>+\<B>. 
- To debug the application, you can press F5. 
- To run the tests you can press \<Ctrl>+\<Shift>+\<T>.

## Build and run locally

If you have a local development environment using gcc, you can build and run the application using MAKE
```bash
cd MAKE
make
./Battleship.exe
```

## Build and run in a Docker container

Alternatively, you can run the application using a Docker Container directly. The repository contains a dockerfile that should work for most scenarios.

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

You can run Unit-Tests in the Docker Container. They are created using CppUnit (https://sourceforge.net/projects/cppunit/). These tests can be found in the folders
- Battleship.GameController.Tests.CppUnit
- Battleship.Ascii.Tests.CppUnit

To prepare for execution of Unit-Tests, use these commands:

```bash
export LD_LIBRARY_PATH=/usr/local/lib
cd /battleship/MAKE
```
For each execution you then just run

```bash
make TestRunner.exe
./TestRunner.exe
```

