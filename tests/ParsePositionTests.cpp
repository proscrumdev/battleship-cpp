#include <stdlib.h>
#include <algorithm>
#include <stdexcept>
#include <iostream>

#include "ParsePositionTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION (ParsePositionTests);

void ParsePositionTests :: ParsePositionTest(void)
{      
	std::string input = "a1";
	Position expected(Letters::A, 1);
	Position result = Program::ParsePosition(input);
            
    CPPUNIT_ASSERT_EQUAL(expected.Column, result.Column);
    CPPUNIT_ASSERT_EQUAL(expected.Row, result.Row);
}


