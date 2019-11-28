#include "stdafx.h"
#include "CppUnitTest.h"

#include "..\Battleship.GameController.Lib\GameController.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace Battleship::GameController::Contracts;
using namespace Battleship::GameController;

namespace Battleship
{
  namespace GameController
  {
    namespace Tests
    {
      TEST_CLASS(IsShipValidTests)
      {
      public:

        /// <summary>
        /// The ship is not valid.
        /// </summary>
        TEST_METHOD(ShipIsNotValid)
        {
          Ship ship("TestShip", 3);

          bool result = GameController::IsShipsValid(ship);

          Assert::IsFalse(result);
        }

        /// <summary>
        /// The ship is valid.
        /// </summary>
        TEST_METHOD(ShipIsValid)
        {
          Ship ship("TestShip", 3);
          ship.AddPosition("A1");
          ship.AddPosition("A1");
          ship.AddPosition("A1");

          bool result = GameController::IsShipsValid(ship);

          Assert::IsTrue(result);
        }
      };
    }
  }
}