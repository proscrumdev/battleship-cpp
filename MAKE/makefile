TARGET = Battleship.exe
CXX = g++
CXXFLAGS = -g -O0 -I../Battleship.Ascii.Lib -I../Battleship.GameController.Lib -I../Battleship.GameController.Tests -I../Battleship.Ascii.Tests

# Google Test paths (assuming they are installed in the default location)
GTEST_DIR = /usr/src/gtest
GTEST_LIB_DIR = /usr/local/lib

# Main target
$(TARGET): Battleship.o Program.a GameController.a 
	$(CXX) $(CXXFLAGS) $^ -o $@

# Object files
Battleship.o: ../Battleship.Ascii/Battleship.Ascii.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Program.a: Program.o
	ar rcs $@ $^

Program.o: ../Battleship.Ascii.Lib/Program.cpp ../Battleship.Ascii.Lib/Program.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

GameController.a: ../Battleship.GameController.Lib/Ship.o ../Battleship.GameController.Lib/Position.o ../Battleship.GameController.Lib/Letters.o ../Battleship.GameController.Lib/GameController.o
	ar rcs $@ $^

Ship.o: ../Battleship.GameController.Lib/Ship.cpp ../Battleship.GameController.Lib/Ship.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

Position.o: ../Battleship.GameController.Lib/Position.cpp ../Battleship.GameController.Lib/Position.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

Letters.o: ../Battleship.GameController.Lib/Letters.cpp ../Battleship.GameController.Lib/Letters.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

GameController.o: ../Battleship.GameController.Lib/GameController.cpp ../Battleship.GameController.Lib/GameController.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Google Test target
TestRunner: CheckIsHitTests.o IsShipValidTests.o ParsePositionTests.o TestRunner.o GameController.o Ship.o Position.o Letters.o Program.o
	$(CXX) $(CXXFLAGS) $^ -o $@ -L$(GTEST_LIB_DIR) -lgtest -lgtest_main -pthread

CheckIsHitTests.o: ../Battleship.GameController.Tests/CheckIsHitTests.cpp ../Battleship.GameController.Tests/CheckIsHitTests.h GameController.o Ship.o Position.o Letters.o
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I$(GTEST_DIR)/include

IsShipValidTests.o: ../Battleship.GameController.Tests/IsShipValidTests.cpp ../Battleship.GameController.Tests/IsShipValidTests.h GameController.o Ship.o Position.o Letters.o
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I$(GTEST_DIR)/include

ParsePositionTests.o: ../Battleship.Ascii.Tests/ParsePositionTests.cpp ../Battleship.Ascii.Tests/ParsePositionTests.h GameController.o Ship.o Position.o Letters.o Program.o
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I$(GTEST_DIR)/include

TestRunner.o: ../Battleship.GameController.Tests/TestRunner.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I$(GTEST_DIR)/include

# Clean target
clean:
	rm -f *.o *.a $(TARGET) TestRunner