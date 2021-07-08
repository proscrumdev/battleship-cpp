#include "Program.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <cctype>
#include <stdexcept>

#include "../Battleship.GameController.Lib/GameController.h"
#include "Colours.h"

#pragma comment(lib,"winmm.lib")  //for MSV C++   

using namespace Battleship::GameController;
using namespace Battleship::GameController::Contracts;

namespace Battleship
{
  namespace Ascii
  {
    ostream& operator<<(ostream &out, Position pos)
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
      cout << Colours::blue;
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
      cout << R"(|                        Welcome to Battleship                         BB-61/  )" << endl;
      cout << R"( \_________________________________________________________________________|   )" << endl;
      cout << endl;
      cout << Colours::colorEnd;

	  InitializeGame();

      StartGame();
    }

    void Program::StartGame()
    {
      //Console::Clear();
      cout << Colours::yellow;
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

      bool endOfTheGame = false;

      do
      {
        cout << endl << endl;
        cout << Colours::blue;
        cout << "=======================================" << endl;
        cout << Colours::yellow;
        cout << R"(Player, it's your turn   )" << endl;

		bool PositionValid = false;
		string input;
		Position position;

        do {
            cout << R"(Enter coordinates for your shot :   )" << endl;
            getline(cin, input);

            try {
                position = ParsePosition(input);
            } catch (...) {
                cout << "Improper position. Try again. ";
                continue;
            }
            break;
        } while (true);

        bool isHit = GameController::GameController::CheckIsHit(enemyFleet, position);
        if (isHit)
        {
            // Console::Beep();
            cout << Colours::green;
			cout << R"(                \         .  ./         )" << endl;
            cout << R"(              \      .:"";'.:..""   /   )" << endl;
            cout << R"(                  (M^^.^~~:.'"").       )" << endl;
            cout << R"(            -   (/  .    . . \ \)  -    )" << endl;
            cout << R"(               ((| :. ~ ^  :. .|))      )" << endl;
            cout << R"(            -   (\- |  \ /  |  /)  -    )" << endl;
            cout << R"(                 -\  \     /  /-        )" << endl;
            cout << R"(                   \  \   /  /          )" << endl;
			cout << ("Yeah ! Nice hit !") << endl;
			cout << Colours::colorEnd;
		}
		else
		{
		    cout << Colours::red;
			cout << ("Miss") << endl;
			cout << Colours::colorEnd;
		}

        endOfTheGame = IsEndOfTheGame();
        if (endOfTheGame) {
            MessageYouWon();
            continue;
        }

        position = GetRandomPosition();
        isHit = GameController::GameController::CheckIsHit(myFleet, position);
        cout << endl;

        if (isHit)
        {
            //Console::Beep();
            cout << Colours::green;
			cout << R"(                \         .  ./         )" << endl;
            cout << R"(              \      .:"";'.:..""   /   )" << endl;
            cout << R"(                  (M^^.^~~:.'"").       )" << endl;
            cout << R"(            -   (/  .    . . \ \)  -    )" << endl;
            cout << R"(               ((| :. ~ ^  :. .|))      )" << endl;
            cout << R"(            -   (\- |  \ /  |  /)  -    )" << endl;
            cout << R"(                 -\  \     /  /-        )" << endl;
            cout << R"(                   \  \   /  /          )" << endl;

			cout << "(Computer shoot in " << position << " and " << "hit your ship !)" << endl;
			cout << Colours::colorEnd;
        }
		else
		{
		    cout << Colours::red;
			cout << "(Computer shoot in " << position << " and missed )   " << endl;
			cout << Colours::colorEnd;
		}

        endOfTheGame = IsEndOfTheGame();
        if (endOfTheGame) {
            MessageYouLost();
            continue;
        }
      }
      while (!endOfTheGame);
    }

	Position Program::ParsePosition(string &input)
    {
	    // validate input string
	    if (!std::isalpha(input.at(0)) || !std::isdigit(input.at(1))) {
	        throw std::invalid_argument("");
	    }
	    if (input.size() > 2) {
	        // all other characters should be digits
	        for (size_t i = 2; i < input.size(); i++) {
	            if (!std::isdigit(input.at(i))) {
	                throw std::invalid_argument("");
	            }
	        }
	    }
      char cColumn = toupper(input.at(0));

	  int nColumn = (cColumn - 'A');
      Letters lColumn = (Letters)nColumn;

      int nRow = std::strtol(input.data() + 1, NULL, 10);

	  Position outPosition;
	  outPosition.Column = lColumn;
	  outPosition.Row = nRow;
	  return outPosition;
    }

    Position Program::GetRandomPosition()
    {
      const int size = 8;
      srand((unsigned int) time(NULL));
      Letters lColumn = (Letters)(rand() % size);
      int nRow = (rand() % size);

      Position position(lColumn, nRow);
      return position;
    }

    // PRIVATE methods
    void Program::MessageYouWon()
    {
        cout << Colours::yellow;
        cout << R"()" << endl;
        cout << R"(You are the winner!)" << endl;
        cout << R"()" << endl;
        cout << Colours::colorEnd;
    }

    void Program::MessageYouLost()
    {
        cout << Colours::yellow;
        cout << R"()" << endl;
        cout << R"(You Lost!)" << endl;
        cout << R"()" << endl;
        cout << Colours::colorEnd;
    }

    bool Program::IsEndOfTheGame()
    {
        //TODO we are waiting for info how to check that ship is dead
        return false;
    }

    void Program::InitializeGame()
    {
      InitializeMyFleet();

      InitializeEnemyFleet(enemyFleet);
    }

	void Program::InitializeMyFleet()
	{
		myFleet = GameController::GameController::InitializeShips();

		cout << Colours::yellow << "Please position your fleet (Game board has size from A to H and 1 to 8) :" << endl;
		for_each(myFleet.begin(), myFleet.end(), [](Ship &ship)
		{
			cout << endl;
			cout << "Please enter the positions for the " << ship.Name << " (size: " << ship.Size << ")" << endl;
			for (int i = 1; i <= ship.Size; i++)
			{
                Position inputPosition;
                do {
                    cout << "Enter position " << i << " of " << ship.Size << "\n";
                    string input;
                    getline(cin, input);
                    try {
                        inputPosition = ParsePosition(input);
                    } catch (...) {
                        cout << "Improper position. Try again. ";
                        continue;
                    }
                    break;
                }while (true);

				ship.AddPosition(inputPosition);
			}
		});
		cout << Colours::colorEnd;
	}

	void Program::InitializeEnemyFleet(list<Ship>& Fleet)
	{
		Fleet = GameController::GameController::InitializeShips();

		for_each(Fleet.begin(), Fleet.end(), [](Ship& ship)
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
			}
		});
	}
  }
}
