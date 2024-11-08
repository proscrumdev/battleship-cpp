#include <gtest/gtest.h>
#include "GameController.h"
#include "Ship.h"
#include "Position.h"
#include "Letters.h"

using namespace Battleship::GameController;
using namespace Battleship::GameController::Contracts;

class CheckIsHitTests : public ::testing::Test {
protected:
    void SetUp() override {
        ships = GameController::InitializeShips();
        int counter = 0;
        for (auto &ship : ships) {
            Letters letter = static_cast<Letters>(counter);
            for (int i = 0; i < ship.Size; ++i) {
                ship.Positions.push_back(Position(letter, i));
            }
            ++counter;
        }
    }

    std::list<Ship> ships;
};

TEST_F(CheckIsHitTests, ShouldHitTheShip) {
    bool result = GameController::CheckIsHit(ships, Position(Letters::A, 1));
    EXPECT_TRUE(result);
}

TEST_F(CheckIsHitTests, ShouldNotHitTheShip) {
    bool result = GameController::CheckIsHit(ships, Position(Letters::B, 8));
    EXPECT_FALSE(result);
}

TEST_F(CheckIsHitTests, ThrowExceptionIfShipIsNull) {
    std::list<Ship> *nullShips = nullptr;
    EXPECT_THROW(GameController::CheckIsHit(*nullShips, Position(Letters::H, 1)), std::invalid_argument);
}