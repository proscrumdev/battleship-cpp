#include "IsShipValidTests.h"

#include <stdlib.h>
#include <algorithm>
#include <stdexcept>
#include <iostream>

CPPUNIT_TEST_SUITE_REGISTRATION (IsShipValidTests);

void IsShipValidTests :: ShipIsNotValid(void)
{      
    Ship ship("TestShip", 3);
    bool result = GameController::IsShipsValid(ship);

    CPPUNIT_ASSERT_EQUAL(false, result);
}

void IsShipValidTests :: ShipIsValid(void)
{      
    Ship ship("TestShip", 3);
    ship.AddPosition("A1");
    ship.AddPosition("A1");
    ship.AddPosition("A1");

    bool result = GameController::IsShipsValid(ship);

    CPPUNIT_ASSERT_EQUAL(true, result);
}
