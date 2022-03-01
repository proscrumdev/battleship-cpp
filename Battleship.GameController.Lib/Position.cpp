#include <string>
#include "Position.h"
#include "Letters.h"

namespace Battleship::GameController::Contracts
    {
      Position::Position(Letters column, int row) : Column(column), Row(row)
      {
      }

      Position::Position(const Position &init) : Column(init.Column), Row(init.Row)
      {
      }

      Position::~Position() = default;

      Position &Position::operator=(const Position &rhs)
      {
        Column = rhs.Column;
        Row = rhs.Row;

        return *this;
      }

      bool Position::operator==(const Position &rhs) const
      {
        return (Column == rhs.Column) && (Row == rhs.Row);
      }

    std::string Position::to_string() const {
      return Battleship::GameController::Contracts::to_string(Column) + std::to_string(Row);
    }

    }

