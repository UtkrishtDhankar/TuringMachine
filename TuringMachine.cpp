#include "TuringMachine.hpp"

/*
 * Private Functions
 */

// by returning the finished vector, we can initialize it properly in the ctor initialization list
std::list<bool> InitializeMemory(const std::list<bool>& init) {
    std::list<bool> v(init);
    v.push_back(false);
    return v;
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
    : memory({}), currentPos(memory.begin())
{
}

TuringMachine::TuringMachine(std::vector<Card> cards_in, std::list<bool> memory_in)
	: cards(cards_in), memory(InitializeMemory(memory_in)), currentPos(memory.begin())
{
}

TuringMachine::TuringMachine(TuringMachine&& other)
{
	cards = std::move(other.cards);
    // as far as I could tell, moving a container does not guarantee iterator validity, but swapping them does
    std::swap(memory, other.memory);
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

const std::list<bool>& TuringMachine::PeekMemory()
{
	return memory;
}
