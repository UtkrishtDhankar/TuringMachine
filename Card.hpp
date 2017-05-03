#pragma once

#include "Instruction.hpp"

class Card 
{
public:
	Instruction         instructions[2];

						Card();
						Card(const Instruction& i0, const Instruction& i1);
						Card(const Card& other);
						Card(Card&& other);

	void				operator=(const Card& other);
};