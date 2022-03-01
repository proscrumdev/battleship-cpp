#include <string>
#include "Letters.h"

namespace Battleship::GameController::Contracts {

std::string to_string(Letters l) {
  switch (l) {
  case A: return "A";
  case B:return "B";
  case C:return "C";
  case D:return "D";
  case E:return "E";
  case F:return "F";
  case G:return "G";
  case H:return "H";
  }
}

}
