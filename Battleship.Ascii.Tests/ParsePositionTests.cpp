#include <gtest/gtest.h>
#include "Program.h"  
#include "Position.h" 

using namespace Battleship::Ascii;

class ParsePositionTests : public ::testing::Test {
protected:
    void SetUp() override {
        // Code here will be called immediately after the constructor (right before each test).
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right before the destructor).
    }
};

TEST_F(ParsePositionTests, ParsePositionTest) {
    std::string input = "a1";
    Position expected(Letters::A, 1);
    Position result = Program::ParsePosition(input);

    EXPECT_EQ(expected.Column, result.Column);
    EXPECT_EQ(expected.Row, result.Row);
}