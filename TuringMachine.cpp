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

	if (i.moveType == MoveType::LEFT) 
	{
		// If we don't have the memory, create it
		if (currentPos == memory.begin()) 
		{
			memory.push_front(false);
		}

		currentPos--;
	}
	else if (i.moveType == MoveType::RIGHT)
	{
		// If we don't have the memory, create it
		if (currentPos == --memory.end())
		{
			memory.push_back(false);
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

TuringMachine::TuringMachine(std::vector<Card> cards_in, std::list<bool> memory_in) :
	cards(cards_in), memory(memory_in)
{
	InitializeMemory();
	currentCard = 0;
}

TuringMachine::TuringMachine(TuringMachine&& other)
{
	cards = std::move(other.cards);
	memory = std::move(other.memory);
	currentPos = other.currentPos;
	currentCard = other.currentCard;
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