#pragma once

#include "Ship.h"

namespace Battleship
{
  namespace GameController
  {
    using namespace Battleship::GameController::Contracts;

    class GameController
    {
    public:
      GameController();
      ~GameController();

	  // kommentieren
	  static bool CheckFleet(std::list<Ship> & ships, bool enemy);

      /// <summary>
      /// Checks the is hit.
      /// </summary>
      /// <param name="ships">
      /// The ships.
      /// </param>
      /// <param name="shot">
      /// The shot.
      /// </param>
      /// <returns>
      /// True if hit, else false
      /// </returns>
      /// <exception cref="std::invalid_argument">
      /// ships
      /// </exception>
      static bool CheckIsHit(std::list<Ship> & ships, Position shot);

      /// <summary>
      ///     The initialize ships.
      /// </summary>
      /// <returns>
      ///     The <see cref="std::list" />.
      /// </returns>
      static std::list<Ship> InitializeShips();

      /// <summary>
      /// The is ships valid.
      /// </summary>
      /// <param name="ship">
      /// The ship.
      /// </param>
      /// <returns>
      /// The <see cref="bool"/>.
      /// </returns>
      static bool IsShipsValid(Ship ship);

      /// <summary>
      /// Get a random position.
      /// </summary>
      /// <param name="size">
      /// The column/row maximum.
      /// </param>
      /// <returns>
      /// The <see cref="Battleship::GameController::Contracts::Position"/>.
      /// </returns>
      static Position GetRandomPosition(int size);

      static bool IsSunk(const Ship &ship);

    };
  }
}


