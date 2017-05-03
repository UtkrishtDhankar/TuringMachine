#include "TuringMachine.hpp"

TuringMachine::TuringMachine()
{
	InitializeMemory();
}

TuringMachine::TuringMachine(std::vector<Card> cards_in) : 
	cards(cards_in)
{
	InitializeMemory();
}

TuringMachine::TuringMachine(const TuringMachine& other)
{
	InitializeMemory();
	cards = other.cards;
}

TuringMachine::TuringMachine(TuringMachine&& other)
{
	InitializeMemory();
	cards = std::move(other.cards);
}

void TuringMachine::InitializeMemory()
{
	memory.push_back(false);
	currentPos = memory.begin();
}
