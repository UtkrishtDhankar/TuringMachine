#pragma once

#include <vector>
#include <list>
#include <utility>

#include "Card.hpp"
#include "Instruction.hpp"

class TuringMachine 
{
private:
	std::vector<Card>			cards;
	std::list<bool>				memory;

	std::list<bool>::iterator	currentPos;

	/*
	 * Initializes the memory of the TuringMachine.
	 */
	void						InitializeMemory();

public:
								TuringMachine();
								TuringMachine(std::vector<Card> cards);
								TuringMachine(const TuringMachine& other);
								TuringMachine(TuringMachine&& other);
};