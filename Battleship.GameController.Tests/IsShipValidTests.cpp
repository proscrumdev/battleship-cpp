#include <gtest/gtest.h>
#include "GameController.h"
#include "Ship.h" 

using namespace Battleship::GameController;
using namespace Battleship::GameController::Contracts;

class IsShipValidTests : public ::testing::Test {
protected:
    void SetUp() override {
        // Code here will be called immediately after the constructor (right before each test).
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right before the destructor).
    }
};

TEST_F(IsShipValidTests, ShipIsNotValid) {
    Ship ship("TestShip", 3);
    bool result = GameController::IsShipsValid(ship);

    EXPECT_FALSE(result);
}

TEST_F(IsShipValidTests, ShipIsValid) {
    Ship ship("TestShip", 3);
    ship.AddPosition("A1");
    ship.AddPosition("A1");
    ship.AddPosition("A1");

    bool result = GameController::IsShipsValid(ship);

    EXPECT_TRUE(result);
}