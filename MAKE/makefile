TARGET = Battleship.exe
CPPUNIT_PATH=/usr/local/lib
CXX = g++
CXXFLAGS = -g -O0

$(TARGET): Battleship.o Program.a GameController.a 
	$(CXX) $(CXXFLAGS) $^ -o $@

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

TestRunner.exe: IsHorizontalVerticalTests.o CheckIsHitTests.o IsShipValidTests.o ParsePositionTests.o TestRunner.o GameController.o Ship.o Position.o Letters.o Program.o
	$(CXX) $(CXXFLAGS) $^ -o $@ -L${CPPUNIT_PATH}/lib -lstdc++ -lcppunit -ldl

CheckIsHitTests.o: ../Battleship.GameController.Tests.CppUnit/CheckIsHitTests.cpp ../Battleship.GameController.Tests.CppUnit/CheckIsHitTests.h GameController.o Ship.o Position.o Letters.o
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I${CPPUNIT_PATH}/include

IsShipValidTests.o: ../Battleship.GameController.Tests.CppUnit/IsShipValidTests.cpp ../Battleship.GameController.Tests.CppUnit/IsShipValidTests.h GameController.o Ship.o Position.o Letters.o
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I${CPPUNIT_PATH}/include

IsHorizontalVerticalTests.o: ../Battleship.GameController.Tests.CppUnit/IsHorizontalVerticalTests.cpp ../Battleship.GameController.Tests.CppUnit/IsHorizontalVerticalTests.h GameController.o Ship.o Position.o Letters.o
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I${CPPUNIT_PATH}/include

ParsePositionTests.o: ../Battleship.Ascii.Tests.CppUnit/ParsePositionTests.cpp ../Battleship.Ascii.Tests.CppUnit/ParsePositionTests.h GameController.o Ship.o Position.o Letters.o Program.o
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I${CPPUNIT_PATH}/include

TestRunner.o: ../Battleship.GameController.Tests.CppUnit/TestRunner.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< -I${CPPUNIT_PATH}/include

clean:
	rm -f *.o *.a $(TARGET)