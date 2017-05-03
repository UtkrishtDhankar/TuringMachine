#include "TuringMachine.hpp"

/*
 * Private Functions
 */
void TuringMachine::InitializeMemory()
{
	memory.push_back(false);
	currentPos = memory.begin();
}

void TuringMachine::ExecuteInstruction(const Instruction& i)
{
	*currentPos = i.overwrite;

	auto oldPos = currentPos;
	if (i.moveType == MoveType::LEFT) 
	{
		// If we don't have the memory, create it
		if (currentPos == memory.begin()) {
			memory.push_front(false);
		}

		currentPos--;
	}
	else if (i.moveType == MoveType::RIGHT)
	{
		// If we don't have the memory, create it
		if (currentPos == --memory.end())
		{
			memory.push_front(false);
		}

		currentPos++;
	}

	currentCard = i.nextCard;
}

/*
 * Constructors
 */
TuringMachine::TuringMachine()
{
	InitializeMemory();
	currentCard = 0;
}

TuringMachine::TuringMachine(std::vector<Card> cards_in) : 
	cards(cards_in)
{
	InitializeMemory();
	currentCard = 0;
}

TuringMachine::TuringMachine(const TuringMachine& other) :
	cards(other.cards), memory(other.memory) 
{
	// TODO figure out how to copy the position iterator
	currentCard = other.currentCard;
}

TuringMachine::TuringMachine(TuringMachine&& other)
{
	InitializeMemory();
	cards = std::move(other.cards);
}

/*
 * Public Functions
 */
void TuringMachine::Tick()
{
	// Get the current card, and execute the appropriate instruction
	ExecuteInstruction(cards[currentCard].instructions[*currentPos]);
}

const std::list<bool>& TuringMachine::PeakMemory()
{
	return memory;
}