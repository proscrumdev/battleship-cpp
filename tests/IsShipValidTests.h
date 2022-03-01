#pragma once

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../Battleship.GameController.Lib/GameController.h"

using namespace std;
using namespace Battleship::GameController;
using namespace Battleship::GameController::Contracts;

class IsShipValidTests : public CPPUNIT_NS :: TestFixture
{
    CPPUNIT_TEST_SUITE (IsShipValidTests);
    CPPUNIT_TEST (ShipIsValid);
    CPPUNIT_TEST (ShipIsNotValid);
    CPPUNIT_TEST_SUITE_END ();

    protected:
        void ShipIsValid (void);
        void ShipIsNotValid (void);
};