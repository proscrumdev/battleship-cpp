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
    std::ostream &operator<<(std::ostream &out, Position pos)
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

    std::list<Ship> Program::myFleet;
    std::list<Ship> Program::enemyFleet;

    bool continue_game(const std::list<Ship>& my_fleet_ships, const std::list<Ship>& enemy_fleet_ships) {
      auto check_destruction = [](const Ship& ship) {
        return ship.is_sunk();
      };

      if (std::all_of(my_fleet_ships.begin(), my_fleet_ships.end(), check_destruction)) {
        std::cout << "You Lose.\n";
        return false;
      }

      if (std::all_of(enemy_fleet_ships.begin(), enemy_fleet_ships.end(), check_destruction)) {
        std::cout << "You Win.\n";
        return false;
      }

      return true;
    }

    void Program::Main()
    {
      std::cout << R"(                                     |__                                       )" << std::endl;
      std::cout << R"(                                     | \ /                                     )" << std::endl;
      std::cout << R"(                                     ---                                       )" << std::endl;
      std::cout << R"(                                     / | [                                     )" << std::endl;
      std::cout << R"(                              !      | |||                                     )" << std::endl;
      std::cout << R"(                            _/|     _/|-++'                                    )" << std::endl;
      std::cout << R"(                        +  +--|    |--|--|_ |-                                 )" << std::endl;
      std::cout << R"(                     { /|__|  |/\__|  |--- |||__/                              )" << std::endl;
      std::cout << R"(                    +---------------___[}-_===_.'____                 /\       )" << std::endl;
      std::cout << R"(                ____`-' ||___-{]_| _[}-  |     |_[___\==--            \/    _  )" << std::endl;
      std::cout << R"( __..._____--==/___]_|__|_____________________________[___\==--____,------' .7 )" << std::endl;
      std::cout << "(|                        " << rang::style::bold << rang::fg::blue << "Welcome to Battleship                      "
           << rang::style::reset << "BB-61/  )" << std::endl;
      std::cout << R"( \_________________________________________________________________________|   )" << std::endl;
      std::cout << std::endl;
      std::cout << "\033[0m";

      InitializeGame();

      StartGame();
    }

    void Program::StartGame()
    {
      // Console::Clear();
      std::cout << R"(                  __     )" << std::endl;
      std::cout << R"(                 /  \    )" << std::endl;
      std::cout << R"(           .-.  |    |   )" << std::endl;
      std::cout << R"(   *    _.-'  \  \__/    )" << std::endl;
      std::cout << R"(    \.-'       \         )" << std::endl;
      std::cout << R"(   /          _/         )" << std::endl;
      std::cout << R"(  |      _  /""          )" << std::endl;
      std::cout << R"(  |     /_\'             )" << std::endl;
      std::cout << R"(   \    \_/              )" << std::endl;
      std::cout << R"(    """"""""             )" << std::endl;

      do
      {

        std::cout << std::endl;
        std::cout << R"(Now it's your turn to shoot!)" << std::endl;

        bool PositionValid = false;
        std::string input;
        Position position;
        std::cout << rang::style::bold << rang::fg::green << "Enter coordinates for your shot: " << rang::style::reset << std::endl;
        getline(std::cin, input);

        position = ParsePosition(input);

        bool isHit = GameController::GameController::CheckIsHit(enemyFleet, position);
        if (isHit)
        {
          // Console::Beep();

          std::cout << R"(                \         .  ./         )" << std::endl;
          std::cout << R"(              \      .:"";'.:..""   /   )" << std::endl;
          std::cout << R"(                  (M^^.^~~:.'"").       )" << std::endl;
          std::cout << R"(            -   (/  .    . . \ \)  -    )" << std::endl;
          std::cout << R"(               ((| :. ~ ^  :. .|))      )" << std::endl;
          std::cout << R"(            -   (\- |  \ /  |  /)  -    )" << std::endl;
          std::cout << R"(                 -\  \     /  /-        )" << std::endl;
          std::cout << R"(                   \  \   /  /          )" << std::endl;
          std::cout << rang::style::bold << rang::fg::red << ("Yeah! Nice hit!") << rang::style::reset << std::endl;
        }
        else
        {
          std::cout << rang::style::bold << rang::fg::blue << ("Oh crap, you missed!") << rang::style::reset << std::endl;
        }

        position = GetRandomPosition();
        isHit = GameController::GameController::CheckIsHit(myFleet, position);
        std::cout << std::endl;

        if (isHit)
        {
          // Console::Beep();

          std::cout << R"(                \         .  ./         )" << std::endl;
          std::cout << R"(              \      .:"";'.:..""   /   )" << std::endl;
          std::cout << R"(                  (M^^.^~~:.'"").       )" << std::endl;
          std::cout << R"(            -   (/  .    . . \ \)  -    )" << std::endl;
          std::cout << R"(               ((| :. ~ ^  :. .|))      )" << std::endl;
          std::cout << R"(            -   (\- |  \ /  |  /)  -    )" << std::endl;
          std::cout << R"(                 -\  \     /  /-        )" << std::endl;
          std::cout << R"(                   \  \   /  /          )" << std::endl;

          std::cout << rang::style::bold << rang::fg::red << "Argh! Computer shoot in " << position << " and hit your ship!" << rang::style::reset << std::endl;
        }
        else
        {
          std::cout << rang::style::bold << rang::fg::blue << "Phew... Computer shoot in " << position << " and missed!" << rang::style::reset << std::endl;
        }
      } while (continue_game(myFleet, enemyFleet));
    }

    Position Program::ParsePosition(std::string input)
    {
      char cColumn = std::toupper(input.at(0));
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

      std::cout << "Battleship is a strategy game where two opposing fleets fight to sink the other.\nThe sea is represented by a board divided in lines (1 to 8) and columns (A to H).\nFirst, let's position your fleet." << std::endl;
      for_each(myFleet.begin(), myFleet.end(), [](Ship &ship)
               {
			std::cout << std::endl;
			std::cout << "The " << ship.Name << " has a size of " << ship.Size << " squares. Where do you want to place it? (coordinate example: B2)" << std::endl;
			for (int i = 1; i <= ship.Size; i++)
			{
        std::cout << rang::style::bold << rang::fg::green << "Coordinate of square " << i << " of " << ship.Size << ":\n" << rang::style::reset << std::endl;
                std::string input;
				getline(std::cin, input);
				Position inputPosition = ParsePosition(input);

				ship.AddPosition(inputPosition);
			} });
    }

    void Program::InitializeEnemyFleet(std::list<Ship> &Fleet)
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
