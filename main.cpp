#include <iostream>
#include <vector>

#include "Instruction.hpp"
#include "Card.hpp"
#include "TuringMachine.hpp"

Instruction GetInstructionFromUser()
{
	char move;
	bool overwrite;
	int nextCard;

	std::cin >> move >> overwrite >> nextCard;

	MoveType moveType;
	if (move == 'l' || move == 'L') 
	{
		moveType = MoveType::LEFT;
	}
	else if (move == 'r' || move == 'R') 
	{
		moveType = MoveType::RIGHT;
	}
	else
	{
		moveType = MoveType::STAY;
	}

	return Instruction(moveType, overwrite, nextCard);
}

int main()
{
	int numCards;
	std::cin >> numCards;
	std::vector<Card> cards(numCards);

	for (int i = 0; i < numCards; i++)
	{
		Instruction i0 = GetInstructionFromUser();
		Instruction i1 = GetInstructionFromUser();
		cards[i] = Card(i0, i1);
	}

	TuringMachine tm(cards);

	int timeToTick;
	std::cin >> timeToTick;
	
	while (timeToTick > 0) {
		for (int i = 0; i < timeToTick; i++) 
		{
			tm.Tick();

			std::cout << "...000 ";
			for (const auto& elem : tm.PeakMemory())
			{
				std::cout << elem;
			}
			std::cout << " 000..." << std::endl;
		}

		std::cin >> timeToTick;
	}

	return 0;
}