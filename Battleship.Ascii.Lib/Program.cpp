#include "Program.h"

#include "../Battleship.GameController.Lib/GameController.h"
#include "../Battleship.GameController.Lib/Letters.h"
#include "rang/rang.h"
#include <algorithm>
#include <iostream>
#include <optional>
#include <random>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma comment(lib, "winmm.lib") // for MSV C++

using namespace Battleship::GameController;
using namespace Battleship::GameController::Contracts;

namespace Battleship::Ascii
{

  Position retrieve_user_position()
  {

    std::string input;

    std::getline(std::cin, input);
    if (std::cin.eof())
    {
      std::cout << "exit game\n";
      exit(0);
    }

    if (input.empty())
    {
      return retrieve_user_position();
    }
    auto inputPosition = Program::ParsePosition(input);

    if (!inputPosition)
    {
      std::cerr << "Provided position is wrong, please enter a coordinate "
                   "between 1 and 8 (and A to H)\n";
      return retrieve_user_position();
    }
    return inputPosition.value();
  }

  std::ostream &operator<<(std::ostream &out, Position pos)
  {
    out << (char)('A' + pos.Column) << pos.Row;
    return out;
  }

  std::list<Ship> Program::myFleet;
  std::list<Ship> Program::enemyFleet;
  std::vector<Position> Program::shots_;

  bool continue_game(const std::list<Ship> &my_fleet_ships,
                     const std::list<Ship> &enemy_fleet_ships)
  {
    auto check_destruction = [](const Ship &ship)
    { return ship.is_sunk(); };

    if (std::all_of(my_fleet_ships.begin(), my_fleet_ships.end(),
                    check_destruction))
    {
      std::cout << "You Lose.\n";
      return false;
    }

    if (std::all_of(enemy_fleet_ships.begin(), enemy_fleet_ships.end(),
                    check_destruction))
    {
      std::cout << "You Win.\n";
      return false;
    }

    return true;
  }

  void Program::Main()
  {
    std::cout
        << R"(                                     |__                                       )"
        << std::endl;
    std::cout
        << R"(                                     | \ /                                     )"
        << std::endl;
    std::cout
        << R"(                                     ---                                       )"
        << std::endl;
    std::cout
        << R"(                                     / | [                                     )"
        << std::endl;
    std::cout
        << R"(                              !      | |||                                     )"
        << std::endl;
    std::cout
        << R"(                            _/|     _/|-++'                                    )"
        << std::endl;
    std::cout
        << R"(                        +  +--|    |--|--|_ |-                                 )"
        << std::endl;
    std::cout
        << R"(                     { /|__|  |/\__|  |--- |||__/                              )"
        << std::endl;
    std::cout
        << R"(                    +---------------___[}-_===_.'____                 /\       )"
        << std::endl;
    std::cout
        << R"(                ____`-' ||___-{]_| _[}-  |     |_[___\==--            \/    _  )"
        << std::endl;
    std::cout
        << R"( __..._____--==/___]_|__|_____________________________[___\==--____,------' .7 )"
        << std::endl;
    std::cout << "(|                        " << rang::style::bold
              << rang::fg::blue << "Welcome to Battleship                      "
              << rang::style::reset << "BB-61/  )" << std::endl;
    std::cout
        << R"( \_________________________________________________________________________|   )"
        << std::endl;
    std::cout << std::endl;
    std::cout << "\033[0m";

    InitializeShots();
    InitializeGame();

    StartGame();
  }

  void Program::InitializeShots()
  {
    for (int i = 0; i < 8; i++)
      for (int j = 1; j <= 8; j++)
      {
        Letters lColumn = (Letters)(i);
        shots_.push_back(Position(lColumn, j));
      }

    auto rng = std::default_random_engine{};
    rng.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::shuffle(std::begin(shots_), std::end(shots_), rng);
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
    int pos = 0;
    do
    {
      std::cout << "\n";
      std::cout << R"(Player, it's your turn   )" << std::endl;
      std::cout << rang::style::bold << rang::fg::green
                << "Enter coordinates for your shot:" << rang::style::reset
                << " (ex: B5)" << std::endl;

      Position position = retrieve_user_position();

      bool isHit =
          GameController::GameController::CheckIsHit(enemyFleet, position);
      if (isHit)
      {
        // Console::Beep();

        std::cout << rang::style::bold << rang::fg::red
                  << "                \\         .  ./         " << std::endl;
        std::cout << "              \\      .:"
                     ";'.:.."
                     "   /   "
                  << std::endl;
        std::cout << "                  (M^^.^~~:.'"
                     ").       "
                  << std::endl;
        std::cout << "            -   (/  .    . . \\ \\)  -    " << std::endl;
        std::cout << "               ((| :. ~ ^  :. .|))      " << std::endl;
        std::cout << "            -   (\\- |  \\ /  |  /)  -    " << std::endl;
        std::cout << "                 -\\  \\     /  /-        " << std::endl;
        std::cout << "                   \\  \\   /  /          " << std::endl;
        std::cout << "Yeah! Nice hit on " << position << "!" << rang::style::reset
                  << std::endl;
      }
      else
      {
        std::cout << rang::style::bold << rang::fg::blue
                  << ("Oh crap, you missed!") << rang::style::reset << std::endl;
      }

      position = shots_[pos];
      pos++;
      isHit = GameController::GameController::CheckIsHit(myFleet, position);
      std::cout << std::endl;

      if (isHit)
      {
        // Console::Beep();

        std::cout << rang::style::bold << rang::fg::red
                  << "                \\         .  ./         " << std::endl;
        std::cout << "              \\      .:"
                     ";'.:.."
                     "   /   "
                  << std::endl;
        std::cout << "                  (M^^.^~~:.'"
                     ").       "
                  << std::endl;
        std::cout << "            -   (/  .    . . \\ \\)  -    " << std::endl;
        std::cout << "               ((| :. ~ ^  :. .|))      " << std::endl;
        std::cout << "            -   (\\- |  \\ /  |  /)  -    " << std::endl;
        std::cout << "                 -\\  \\     /  /-        " << std::endl;
        std::cout << "                   \\  \\   /  /          " << std::endl;
        std::cout << "Argh! Computer shoot in " << position
                  << " and hit your ship!" << rang::style::reset << std::endl;
      }
      else
      {
        std::cout << rang::style::bold << rang::fg::blue
                  << "Phew... Computer shoot in " << position << " and missed!"
                  << rang::style::reset << std::endl;
      }
    } while (continue_game(myFleet, enemyFleet));
  }

  std::optional<Position> Program::ParsePosition(std::string input)
  {
    if (input.size() != 2)
    {
      return std::nullopt;
    }
    char cColumn = std::toupper(input.at(0));
    char cRow = input.at(1);

    int nRow = cRow - '0';

    if (nRow < 1 || nRow > 8 || cColumn < 'A' || cColumn > 'H')
    {
      return std::nullopt;
    }

    int nColumn = (cColumn - 'A');

    Position outPosition;
    outPosition.Column = static_cast<Letters>(nColumn);
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

    std::cout
        << "Battleship is a strategy game where two opposing fleets fight to "
           "sink the other.\nThe sea is represented by a board divided in lines "
           "(1 to 8) and columns (A to H).\nFirst, let's position your fleet."
        << std::endl;
    for_each(myFleet.begin(), myFleet.end(), [](Ship &ship)
             {
    std::cout << std::endl;
    std::cout
        << "The " << ship.Name << " has a size of " << ship.Size
        << " squares. Where do you want to place it? (coordinate example: B2)"
        << std::endl;
    for (int i = 1; i <= ship.Size; i++) {
      std::cout << rang::style::bold << rang::fg::green
                << "Coordinate of square " << i << " of " << ship.Size << ":\n"
                << rang::style::reset << std::endl;
      ship.AddPosition(retrieve_user_position());
    } });
  }

  void Program::InitializeEnemyFleet(std::list<Ship> &Fleet)
  {
    Fleet = GameController::GameController::InitializeShips();

    for_each(Fleet.begin(), Fleet.end(), [](Ship &ship)
             {
    if (ship.Name == "Aircraft Carrier") {
      ship.Positions.insert(ship.Positions.end(), Position(Letters::B, 4));
      ship.Positions.insert(ship.Positions.end(), Position(Letters::B, 5));
      ship.Positions.insert(ship.Positions.end(), Position(Letters::B, 6));
      ship.Positions.insert(ship.Positions.end(), Position(Letters::B, 7));
      ship.Positions.insert(ship.Positions.end(), Position(Letters::B, 8));
    }
    if (ship.Name == "Battleship") {
      ship.Positions.insert(ship.Positions.end(), Position(Letters::E, 5));
      ship.Positions.insert(ship.Positions.end(), Position(Letters::E, 6));
      ship.Positions.insert(ship.Positions.end(), Position(Letters::E, 7));
      ship.Positions.insert(ship.Positions.end(), Position(Letters::E, 8));
    }
    if (ship.Name == "Submarine") {
      ship.Positions.insert(ship.Positions.end(), Position(Letters::A, 3));
      ship.Positions.insert(ship.Positions.end(), Position(Letters::B, 3));
      ship.Positions.insert(ship.Positions.end(), Position(Letters::C, 3));
    }
    if (ship.Name == "Destroyer") {
      ship.Positions.insert(ship.Positions.end(), Position(Letters::F, 8));
      ship.Positions.insert(ship.Positions.end(), Position(Letters::G, 8));
      ship.Positions.insert(ship.Positions.end(), Position(Letters::H, 8));
    }
    if (ship.Name == "Patrol Boat") {
      ship.Positions.insert(ship.Positions.end(), Position(Letters::C, 5));
      ship.Positions.insert(ship.Positions.end(), Position(Letters::C, 6));
    } });
  }
} // namespace Battleship::Ascii
