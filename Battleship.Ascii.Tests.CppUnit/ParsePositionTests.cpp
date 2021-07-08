#include "ParsePositionTests.h"

#include <stdlib.h>
#include <algorithm>
#include <stdexcept>
#include <iostream>

CPPUNIT_TEST_SUITE_REGISTRATION (ParsePositionTests);

void ParsePositionTests :: ParsePositionTest(void)
{      
    {
        string input = "a1";
        Position expected(Letters::A, 1);
        try {
            Position result = Program::ParsePosition(input);
            CPPUNIT_ASSERT_EQUAL(expected.Column, result.Column);
            CPPUNIT_ASSERT_EQUAL(expected.Row, result.Row);
        } catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }
    {
        string input = "b22";
        Position expected(Letters::B, 22);
        try {
            Position result = Program::ParsePosition(input);
            CPPUNIT_ASSERT_EQUAL(expected.Column, result.Column);
            CPPUNIT_ASSERT_EQUAL(expected.Row, result.Row);
        } catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }
}

void ParsePositionTests :: ParseInvalidPositionTest(void)
{
    {
        try {
            string input = "1a";
            Position result = Program::ParsePosition(input);
        } catch (std::invalid_argument &e) {
            CPPUNIT_ASSERT(true);
        } catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }
    {
        try {
            string input = "a2a";
            Position result = Program::ParsePosition(input);
        } catch (std::invalid_argument &e) {
            CPPUNIT_ASSERT(true);
        } catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }
    {
        try {
            string input = "1";
            Position result = Program::ParsePosition(input);
        } catch (std::invalid_argument &e) {
            CPPUNIT_ASSERT(true);
        } catch (...) {
            CPPUNIT_ASSERT(false);
        }
    }
}

