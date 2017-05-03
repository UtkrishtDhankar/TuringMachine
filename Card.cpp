#include "Card.hpp"

Card::Card()
{
	// The instructions should be their default selves
}

Card::Card(const Instruction& i0, const Instruction& i1)
{
	instructions[0] = i0;
	instructions[1] = i1;
}

Card::Card(const Card& other)
{
	instructions[0] = other.instructions[0];
	instructions[1] = other.instructions[1];
}

Card::Card(Card&& other)
{
	instructions[0] = other.instructions[0];
	instructions[1] = other.instructions[1];
}

void Card::operator=(const Card& other)
{
	instructions[0] = other.instructions[0];
	instructions[1] = other.instructions[1];
}