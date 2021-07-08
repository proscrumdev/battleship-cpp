#include "GameController.h"
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <stdexcept>
#include <iostream>

namespace Battleship
{
  namespace GameController
  {
	using namespace std;

	GameController::GameController()
	{
	}

	GameController::~GameController()
	{
	}

	bool GameController::CheckIsHit(std::list<Ship> & ships, Position shot)
	{
	  if (&ships == nullptr)
		throw std::invalid_argument(std::string("argument 'ships' is invalid"));

	  auto shipFound = find_if(ships.begin(), ships.end(), [&shot](Ship &s)
	  {
		auto posFound = find_if(s.Positions.begin(), s.Positions.end(), [&shot](Position &p)
		{
			if (p == shot)
			{
				return true;
			}

			return false;
		});
		return posFound != s.Positions.end();
	  });

	  return shipFound != ships.end();
	}

	list<Ship> GameController::InitializeShips()
	{
	  list<Ship> ships;
	  ships.insert(ships.end(), Ship("Aircraft Carrier", 5));
	  ships.insert(ships.end(), Ship("Battleship", 4));
	  ships.insert(ships.end(), Ship("Submarine", 3));
	  ships.insert(ships.end(), Ship("Destroyer", 3));
	  ships.insert(ships.end(), Ship("Patrol Boat", 2));

	  return ships;
	}

	bool GameController::IsShipsValid(Ship ship)
	{
	  return ship.Positions.size() == ship.Size;
	}

	Position GameController::GetRandomPosition(int size)
	{
	  srand((unsigned int) time(NULL));
	  Letters lColumn = (Letters)(rand() % size);
	  int nRow = (rand() % size);

	  Position position(lColumn, nRow);
	  return position;
	}

	bool GameController::IsSunk(const Ship &ship)
	{
		bool isSunk = true;

		for(auto pos = ship.Positions.begin(); pos != ship.Positions.end(); pos++)
		{
			isSunk &= pos->isHit;
		}
		return isSunk;
	}
  }
}




