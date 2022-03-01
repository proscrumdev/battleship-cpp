#pragma once

#include <list>
#include <optional>
#include <vector>

#include "../Battleship.GameController.Lib/Position.h"
#include "../Battleship.GameController.Lib/Ship.h"

using namespace Battleship::GameController::Contracts;

namespace Battleship::Ascii {
class Program {
private:
  static std::list<Ship> myFleet;
  static std::list<Ship> enemyFleet;
  static std::vector<Position> shots_;

public:
  static void Main();
  static void StartGame();

private:
  static void InitializeGame();

  static void InitializeMyFleet();
  static void InitializeShots();
  static void InitializeEnemyFleet(std::list<Ship> &Fleet);

public:
  static std::optional<Position> ParsePosition(std::string input);
  static Position GetRandomPosition();
};

} // namespace Battleship::Ascii
