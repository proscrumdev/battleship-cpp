#include "Colours.h"

namespace Battleship {
namespace Ascii {

const Colours::Colour Colours::blue = { 0x1b, '[', '0', ';', '3', '4', 'm', 0 };
const Colours::Colour Colours::green = { 0x1b, '[', '0', ';', '3', '2', 'm', 0 };
const Colours::Colour Colours::red = { 0x1b, '[', '0', ';', '3', '1', 'm', 0 };
const Colours::Colour Colours::yellow = { 0x1b, '[', '0', ';', '3', '3', 'm', 0 };
const Colours::Colour Colours::colorEnd = { 0x1b, '[', '0', 'm', 0 };

} /* namespace Ascii */
} /* namespace Battleship */
