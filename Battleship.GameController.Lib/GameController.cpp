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

    void print_enemy_status_after_sink(const std::list<Ship>& ships) {
      for (const auto& ship : ships) {
        const bool is_sunk = ship.is_sunk();
        std::string sunk_str = "alive";
        if (is_sunk) {
          sunk_str = "sunk : positions was ";
          for (const Position& pos : ship.Positions) {
            sunk_str += pos.to_string() +  + ";";
          }
        }

        std::cout << ship.Name << ": is " << sunk_str << "\n";
      }
    }

	bool GameController::CheckIsHit(std::list<Ship> & ships, Position shot)
	{
	  if (&ships == nullptr)
		throw std::invalid_argument(std::string("argument 'ships' is invalid"));

	  auto shipFound = find_if(ships.begin(), ships.end(), [&shot](Ship &s) {
		return s.hit(shot);
	  });

      const bool has_hit = (shipFound != ships.end());
      if (has_hit && shipFound->is_sunk()) {
        std::cout << "Enemy Ship " << shipFound-> Name << " has been sunk\n";
        print_enemy_status_after_sink(ships);
      }

	  return has_hit;
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
  }
}




