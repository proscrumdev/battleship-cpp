#pragma once

#include <string>
#include <list>

#include "Position.h"

namespace Battleship
{
  namespace GameController
  {
	namespace Contracts
	{
	  class Ship
	  {

	  public:
		Ship();
		Ship(std::string Name, int Size);
		~Ship();

	  public:

		/// <summary>
		/// Gets or sets the name.
		/// </summary>
		std::string Name;

		/// <summary>
		/// Gets or sets the positions.
		/// </summary>
		std::list<Position> Positions;

		/// <summary>
		/// Gets or sets the size.
		/// </summary>
		int Size;

		/// <summary>
		/// The add position.
		/// </summary>
		/// <param name="input">
		/// The input.
		/// </param>
		void AddPosition(std::string input);
		void AddPosition(const Position &input);
	  };
	}
  }
}

