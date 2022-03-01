#include <stdlib.h>
#include <algorithm>
#include <stdexcept>
#include <iostream>

#include "ParsePositionTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION (ParsePositionTests);

void ParsePositionTests::ParsePositionTest(void) {
  std::string input = "a1";
  Position expected(Letters::A, 1);
  auto result = Program::ParsePosition(input);

  CPPUNIT_ASSERT(result.has_value());
  CPPUNIT_ASSERT_EQUAL(expected.Column, result->Column);
  CPPUNIT_ASSERT_EQUAL(expected.Row, result->Row);
}

void ParsePositionTests::ParsePositionNoneTest(void) {
  std::string input_wrong_number = "a9";
  auto result_number = Program::ParsePosition(input_wrong_number);

  CPPUNIT_ASSERT(not result_number.has_value());

  input_wrong_number = "a0";
  result_number = Program::ParsePosition(input_wrong_number);

  CPPUNIT_ASSERT(not result_number.has_value());

  std::string input_wrong_letter = "z1";
  auto result_letter = Program::ParsePosition(input_wrong_letter);

  CPPUNIT_ASSERT(not result_letter.has_value());

  std::string input_wrong_size = "A11";
  auto result_size = Program::ParsePosition(input_wrong_size);

  CPPUNIT_ASSERT(not result_size.has_value());

}

