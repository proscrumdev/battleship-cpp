#include "Position.h"

namespace Battleship
{
  namespace GameController
  {
    namespace Contracts
    {
      Position::Position(Letters column, int row) : Column(column), Row(row)
      {
      }

      Position::Position(const Position &init) : Column(init.Column), Row(init.Row)
      {
      }

      Position::~Position()
      {
      }

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
    }
  }
}

