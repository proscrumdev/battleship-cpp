#pragma once

#include <list>
#include <optional>

#include "../Battleship.GameController.Lib/Ship.h"

using namespace Battleship::GameController::Contracts;

namespace Battleship::Ascii {
class Program {
private:
  static std::list<Ship> myFleet;
  static std::list<Ship> enemyFleet;

public:
  static void Main();
  static void StartGame();

private:
  static void InitializeGame();

	  static void InitializeMyFleet();
	  static void InitializeEnemyFleet(std::list<Ship> &Fleet);

	public:
	  static Position ParsePosition(std::string input);
	  static Position GetRandomPosition();
};

}

