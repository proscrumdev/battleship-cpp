#include <algorithm>
#include "CppUnitTest.h"

#include "..\Battleship.GameController.Lib\GameController.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace Battleship::GameController::Contracts;
using namespace Battleship::GameController;

namespace Battleship
{
  namespace GameController
  {
    namespace Tests
    {
      TEST_CLASS(GameControllerTests)
      {
      public:

        /// <summary>
        /// The should hit the ship.
        /// </summary>
        TEST_METHOD(ShouldHitTheShip)
        {
          list<Ship> ships = GameController::InitializeShips();

          int counter = 0;
          for_each(ships.begin(), ships.end(), [&counter](Ship &ship)
          {
            Letters letter = (Letters)counter;
            for (int i = 0; i < ship.Size; i++)
            {
              ship.Positions.insert(ship.Positions.end(), Position(letter, i));
            }
          });

          bool result = GameController::CheckIsHit(ships, Position(Letters::A, 1));
          Assert::IsTrue(result);
        }

        /// <summary>
        /// The should not hit the ship.
        /// </summary>
        TEST_METHOD(ShouldNotHitTheShip)
        {
          list<Ship> ships = GameController::InitializeShips();

          int counter = 0;
          for_each(ships.begin(), ships.end(), [&counter](Ship &ship)
          {
            Letters letter = (Letters)counter;
            for (int i = 0; i < ship.Size; i++)
            {
              ship.Positions.insert(ship.Positions.end(), Position(letter, i));
            }
          });

          bool result = GameController::CheckIsHit(ships, Position(Letters::B, 1));
          Assert::IsFalse(result);
        }

        /// <summary>
        /// The throw exception if ship is null.
        /// </summary>
        TEST_METHOD(ThrowExceptionIfShipIsNull)
        {
          Assert::ExpectException<std::invalid_argument &>([]()
          {
            list<Ship> &ships = *((list<Ship> *) nullptr);
            GameController::CheckIsHit(ships, Position(Letters::H, 1));
          });
        }
      };
    }
  }
}