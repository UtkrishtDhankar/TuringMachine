#pragma once

#include <vector>
#include <utility>

#include "Card.hpp"
#include "Instruction.hpp"

class TuringMachine 
{
private:
	std::vector<Card>		cards;

public:
							TuringMachine();
							TuringMachine(std::vector<Card> cards);
							TuringMachine(const TuringMachine& other);
							TuringMachine(TuringMachine&& other);
};