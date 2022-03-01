#include "CheckIsHitTests.h"

#include <stdlib.h>
#include <algorithm>
#include <stdexcept>
#include <iostream>

CPPUNIT_TEST_SUITE_REGISTRATION (CheckIsHitTests);

void CheckIsHitTests::ShouldHitTheShip(void) {
  std::list<Ship> ships = GameController::InitializeShips();

  int counter = 0;
  std::for_each(ships.begin(), ships.end(), [&counter](Ship& ship) {
    Letters letter = (Letters)counter;
    for (int i = 0; i < ship.Size; i++) {
      ship.Positions.insert(ship.Positions.end(), Position(letter, i));
    }
  });

  bool result = GameController::CheckIsHit(ships, Position(Letters::A, 1));
  CPPUNIT_ASSERT_EQUAL(true, result);
}

void CheckIsHitTests::ShouldNotHitTheShip(void) {
  std::list<Ship> ships = GameController::InitializeShips();

  int counter = 0;
  std::for_each(ships.begin(), ships.end(), [&counter](Ship& ship) {
    Letters letter = (Letters)counter;
    for (int i = 0; i < ship.Size; i++) {
      ship.Positions.insert(ship.Positions.end(), Position(letter, i));
    }
  });

  bool result = GameController::CheckIsHit(ships, Position(Letters::B, 1));
  CPPUNIT_ASSERT_EQUAL(false, result);
}

void CheckIsHitTests::ThrowExceptionIfShipIsNull(void) {
  // list<Ship> &ships = *((list<Ship> *) nullptr);
  // CPPUNIT_ASSERT_THROW(GameController::CheckIsHit(ships, Position(Letters::H, 1), std::invalid_argument);
}