#include <iostream>
#include <vector>

#include "Instruction.hpp"
#include "Card.hpp"
#include "TuringMachine.hpp"

int main()
{
	Instruction i1(MoveType::RIGHT, true, 0);
	Instruction i2(MoveType::RIGHT, true, 0);

	Card card(i1, i2);
	std::vector<Card> cards;
	cards.push_back(card);

	TuringMachine tm(cards);

	for (int i = 0; i < 10; i++) 
	{
		tm.Tick();

		for (const auto& elem : tm.PeakMemory())
		{
			std::cout << elem;
		}
		std::cout << std::endl;
	}

	return 0;
}