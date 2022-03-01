#include "ParsePositionTests.h"

#include <stdlib.h>
#include <algorithm>
#include <stdexcept>
#include <iostream>

CPPUNIT_TEST_SUITE_REGISTRATION (ParsePositionTests);

void ParsePositionTests :: ParsePositionTest(void)
{      
	string input = "a1";
	Position expected(Letters::A, 1);
	Position result = Program::ParsePosition(input);
            
    CPPUNIT_ASSERT_EQUAL(expected.Column, result.Column);
    CPPUNIT_ASSERT_EQUAL(expected.Row, result.Row);
}


