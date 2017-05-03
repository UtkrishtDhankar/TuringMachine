#pragma once

#include "Instruction.hpp"

class Card 
{
public:
	Instruction         instructions[2];
	unsigned int 		cardNumber;

						Card();
						Card(unsigned int cardNumber, const Instruction& i0, const Instruction& i1);
						Card(const Card& other);
						Card(Card&& other);

	void				operator=(const Card& other);
};