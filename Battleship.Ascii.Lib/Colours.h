#pragma once

#include <string>

namespace Battleship {
namespace Ascii {

class Colours {
public:
    using Colour = std::string;
    static const Colour blue;
    static const Colour green;
    static const Colour red;
    static const Colour yellow;
    static const Colour colorEnd;
};

} /* namespace Ascii */
} /* namespace Battleship */
