#include "Ship.h"
#include <iostream>
using namespace std;

namespace Battleship
{
  namespace GameController
  {
	namespace Contracts
	{
	  Ship::Ship()
	  {
	  }

	  Ship::Ship(std::string Name, int Size) : Name(Name), Size(Size)
	  {
	  }

	  Ship::~Ship()
	  {
	  }

	  void Ship::AddPosition(string input)
	  {
		char cColumn = toupper(input.at(0));
		char cRow = input.at(1);  
		
		Letters lColumn = (Letters) (cColumn - 'A');
		int nRow = cRow - '0';
		
		Position position(lColumn, nRow);
		Positions.insert(Positions.begin(), position);
	  }
	  void Ship::AddPosition(const Position &inputPosition)
	  {
		  Positions.insert(Positions.begin(), inputPosition);
	  }
	}
  }
}


