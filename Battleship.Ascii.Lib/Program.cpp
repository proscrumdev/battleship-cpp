#include "Program.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include "rang/rang.h"
#include "../Battleship.GameController.Lib/GameController.h"

#pragma comment(lib, "winmm.lib") // for MSV C++

using namespace Battleship::GameController;
using namespace Battleship::GameController::Contracts;

namespace Battleship
{
  namespace Ascii
  {
    ostream &operator<<(ostream &out, Position pos)
    {
      out << (char)('A' + pos.Column) << pos.Row;
      return out;
    }

    Program::Program()
    {
    }

    Program::~Program()
    {
    }

    list<Ship> Program::myFleet;
    list<Ship> Program::enemyFleet;

    void Program::Main()
    {
      cout << R"(                                     |__                                       )" << endl;
      cout << R"(                                     | \ /                                     )" << endl;
      cout << R"(                                     ---                                       )" << endl;
      cout << R"(                                     / | [                                     )" << endl;
      cout << R"(                              !      | |||                                     )" << endl;
      cout << R"(                            _/|     _/|-++'                                    )" << endl;
      cout << R"(                        +  +--|    |--|--|_ |-                                 )" << endl;
      cout << R"(                     { /|__|  |/\__|  |--- |||__/                              )" << endl;
      cout << R"(                    +---------------___[}-_===_.'____                 /\       )" << endl;
      cout << R"(                ____`-' ||___-{]_| _[}-  |     |_[___\==--            \/    _  )" << endl;
      cout << R"( __..._____--==/___]_|__|_____________________________[___\==--____,------' .7 )" << endl;
      cout << "(|                        " << rang::style::bold << rang::fg::blue << "Welcome to Battleship                      "
           << rang::style::reset << "BB-61/  )" << endl;
      cout << R"( \_________________________________________________________________________|   )" << endl;
      cout << endl;
      cout << "\033[0m";

      InitializeGame();

      StartGame();
    }

    void Program::StartGame()
    {
      // Console::Clear();
      cout << R"(                  __     )" << endl;
      cout << R"(                 /  \    )" << endl;
      cout << R"(           .-.  |    |   )" << endl;
      cout << R"(   *    _.-'  \  \__/    )" << endl;
      cout << R"(    \.-'       \         )" << endl;
      cout << R"(   /          _/         )" << endl;
      cout << R"(  |      _  /""          )" << endl;
      cout << R"(  |     /_\'             )" << endl;
      cout << R"(   \    \_/              )" << endl;
      cout << R"(    """"""""             )" << endl;

      do
      {
        cout << endl;
        cout << R"(Now it's your turn to shoot!)" << endl;

        bool PositionValid = false;
        string input;
        Position position;
        cout << rang::style::bold << rang::fg::green << "Enter coordinates for your shot: " << rang::style::reset << endl;
        getline(cin, input);

        position = ParsePosition(input);

        bool isHit = GameController::GameController::CheckIsHit(enemyFleet, position);
        if (isHit)
        {
          // Console::Beep();

          cout << R"(                \         .  ./         )" << endl;
          cout << R"(              \      .:"";'.:..""   /   )" << endl;
          cout << R"(                  (M^^.^~~:.'"").       )" << endl;
          cout << R"(            -   (/  .    . . \ \)  -    )" << endl;
          cout << R"(               ((| :. ~ ^  :. .|))      )" << endl;
          cout << R"(            -   (\- |  \ /  |  /)  -    )" << endl;
          cout << R"(                 -\  \     /  /-        )" << endl;
          cout << R"(                   \  \   /  /          )" << endl;
          cout << rang::style::bold << rang::fg::red << ("Yeah! Nice hit!") << rang::style::reset << endl;
        }
        else
        {
          cout << rang::style::bold << rang::fg::blue << ("Oh crap, you missed!") << rang::style::reset << endl;
        }

        position = GetRandomPosition();
        isHit = GameController::GameController::CheckIsHit(myFleet, position);
        cout << endl;

        if (isHit)
        {
          // Console::Beep();

          cout << R"(                \         .  ./         )" << endl;
          cout << R"(              \      .:"";'.:..""   /   )" << endl;
          cout << R"(                  (M^^.^~~:.'"").       )" << endl;
          cout << R"(            -   (/  .    . . \ \)  -    )" << endl;
          cout << R"(               ((| :. ~ ^  :. .|))      )" << endl;
          cout << R"(            -   (\- |  \ /  |  /)  -    )" << endl;
          cout << R"(                 -\  \     /  /-        )" << endl;
          cout << R"(                   \  \   /  /          )" << endl;

          cout << rang::style::bold << rang::fg::red << "Argh! Computer shoot in " << position << " and hit your ship!" << rang::style::reset << endl;
        }
        else
        {
          cout << rang::style::bold << rang::fg::blue << "Phew... Computer shoot in " << position << " and missed!" << rang::style::reset << endl;
        }
      } while (true);
    }

    Position Program::ParsePosition(string input)
    {
      char cColumn = toupper(input.at(0));
      char cRow = input.at(1);

      int nColumn = (cColumn - 'A');
      Letters lColumn = (Letters)nColumn;

      int nRow = cRow - '0';

      Position outPosition;
      outPosition.Column = lColumn;
      outPosition.Row = nRow;
      return outPosition;
    }

    Position Program::GetRandomPosition()
    {
      const int size = 8;
      srand((unsigned int)time(NULL));
      Letters lColumn = (Letters)(rand() % size);
      int nRow = (rand() % size);

      Position position(lColumn, nRow);
      return position;
    }

    void Program::InitializeGame()
    {
      InitializeMyFleet();

      InitializeEnemyFleet(enemyFleet);
    }

    void Program::InitializeMyFleet()
    {
      myFleet = GameController::GameController::InitializeShips();

      cout << "Battleship is a strategy game where two opposing fleets fight to sink the other.\nThe sea is represented by a board divided in lines (1 to 8) and columns (A to H).\nFirst, let's position your fleet." << endl;
      for_each(myFleet.begin(), myFleet.end(), [](Ship &ship)
               {
			cout << endl;
			cout << "The " << ship.Name << " has a size of " << ship.Size << " squares. Where do you want to place it? (coordinate example: B2)" << endl;
			for (int i = 1; i <= ship.Size; i++)
			{
        cout << rang::style::bold << rang::fg::green << "Coordinate of square " << i << " of " << ship.Size << ":\n" << rang::style::reset << endl;
				string input;
				getline(cin, input);
				Position inputPosition = ParsePosition(input);

				ship.AddPosition(inputPosition);
			} });
    }

    void Program::InitializeEnemyFleet(list<Ship> &Fleet)
    {
      Fleet = GameController::GameController::InitializeShips();

      for_each(Fleet.begin(), Fleet.end(), [](Ship &ship)
               {
			if (ship.Name == "Aircraft Carrier")
			{
				ship.Positions.insert(ship.Positions.end(), Position(Letters::B, 4));
				ship.Positions.insert(ship.Positions.end(), Position(Letters::B, 5));
				ship.Positions.insert(ship.Positions.end(), Position(Letters::B, 6));
				ship.Positions.insert(ship.Positions.end(), Position(Letters::B, 7));
				ship.Positions.insert(ship.Positions.end(), Position(Letters::B, 8));
			}
			if (ship.Name == "Battleship")
			{
				ship.Positions.insert(ship.Positions.end(), Position(Letters::E, 5));
				ship.Positions.insert(ship.Positions.end(), Position(Letters::E, 6));
				ship.Positions.insert(ship.Positions.end(), Position(Letters::E, 7));
				ship.Positions.insert(ship.Positions.end(), Position(Letters::E, 8));
			}
			if (ship.Name == "Submarine")
			{
				ship.Positions.insert(ship.Positions.end(), Position(Letters::A, 3));
				ship.Positions.insert(ship.Positions.end(), Position(Letters::B, 3));
				ship.Positions.insert(ship.Positions.end(), Position(Letters::C, 3));
			}
			if (ship.Name == "Destroyer")
			{
				ship.Positions.insert(ship.Positions.end(), Position(Letters::F, 8));
				ship.Positions.insert(ship.Positions.end(), Position(Letters::G, 8));
				ship.Positions.insert(ship.Positions.end(), Position(Letters::H, 8));
			}
			if (ship.Name == "Patrol Boat")
			{
				ship.Positions.insert(ship.Positions.end(), Position(Letters::C, 5));
				ship.Positions.insert(ship.Positions.end(), Position(Letters::C, 6));
			} });
    }
  }
}
