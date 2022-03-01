#pragma once

namespace Battleship::GameController::Contracts
    {
      enum Letters
      {
        A,
        B,
        C,
        D,
        E,
        F,
        G,
        H
      };

      std::string to_string(Letters l);
    }

