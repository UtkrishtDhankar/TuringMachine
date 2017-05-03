#pragma once

#include "Instruction.hpp"

class Card 
{
public:
	Instruction         instructions[2] = {}; // direct member initialization to avoid cluttering up constructors, or leaving member uninitialized

						Card() = default; // if direct initializion is done, we can let the compiler generate this ctor for us
						Card(const Instruction& i0, const Instruction& i1);
};
