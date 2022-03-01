#include <iostream>
#include <algorithm>

#include "Ship.h"

using namespace std;

namespace Battleship::GameController::Contracts
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

      bool Ship::hit(const Position& position) {
        bool already_hit = std::any_of(this->hit_mapping.begin(), this->hit_mapping.end(), [&position](Position& hit_pos) {
          return hit_pos == position;
        });
        if (already_hit) {
          return false;
        }

        auto posFound = std::find_if(this->Positions.begin(), this->Positions.end(), [&position](Position& p) {
          return (p == position);
        });
        const bool has_been_hit = posFound != this->Positions.end();
        if (has_been_hit) {
          this->hit_mapping.emplace_back(position);
        }
        return has_been_hit;
      }

      bool Ship::is_sunk() const {
        return this->hit_mapping.size() == this->Positions.size();
      }

}


