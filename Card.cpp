#include "Card.hpp"

Card::Card()
{
	cardNumber = 0;

	// The instructions should be their default selves
}

Card::Card(unsigned int cardNumber, const Instruction& i0, const Instruction& i1)
{
	cardNumber = cardNumber;
	instructions[0] = i0;
	instructions[1] = i1;
}

Card::Card(const Card& other)
{
	cardNumber = other.cardNumber;
	instructions[0] = other.instructions[0];
	instructions[1] = other.instructions[1];
}

Card::Card(Card&& other)
{
	cardNumber = other.cardNumber;
	instructions[0] = other.instructions[0];
	instructions[1] = other.instructions[1];
}

void Card::operator=(const Card& other)
{
	cardNumber = other.cardNumber;
	instructions[0] = other.instructions[0];
	instructions[1] = other.instructions[1];
}