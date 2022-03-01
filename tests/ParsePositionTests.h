#pragma once

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../Battleship.Ascii.Lib/Program.h"
#include "../Battleship.GameController.Lib/GameController.h"

using namespace Battleship::Ascii;

class ParsePositionTests : public CPPUNIT_NS :: TestFixture
{
    CPPUNIT_TEST_SUITE (ParsePositionTests);
    CPPUNIT_TEST (ParsePositionTest);
    CPPUNIT_TEST (ParsePositionNoneTest);
    CPPUNIT_TEST_SUITE_END ();

    protected:
      void ParsePositionTest (void);
      void ParsePositionNoneTest (void);
};