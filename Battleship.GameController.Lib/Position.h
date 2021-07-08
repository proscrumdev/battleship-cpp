#pragma once

#include "Letters.h"

namespace Battleship
{
  namespace GameController
  {
    namespace Contracts
    {
      class Position
      {
      public:
        Position(Letters column = Letters::A, int row = 0);
        Position(const Position &init);
        ~Position();
      
      public:
        Letters Column;
        int Row;
        bool isHit;

      public:
        Position &operator=(const Position &rhs);
        bool operator==(const Position &rhs) const;
      };
    }
  }
}


