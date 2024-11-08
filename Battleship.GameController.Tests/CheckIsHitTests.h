#pragma once

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../Battleship.GameController.Lib/GameController.h"

using namespace std;
using namespace Battleship::GameController;
using namespace Battleship::GameController::Contracts;

class CheckIsHitTests : public CPPUNIT_NS :: TestFixture
{
    CPPUNIT_TEST_SUITE (CheckIsHitTests);
    CPPUNIT_TEST (ShouldHitTheShip);
    CPPUNIT_TEST (ShouldNotHitTheShip);
    CPPUNIT_TEST (ThrowExceptionIfShipIsNull);
    CPPUNIT_TEST_SUITE_END ();

    protected:
        void ShouldHitTheShip (void);
        void ShouldNotHitTheShip (void);
        void ThrowExceptionIfShipIsNull (void);
};