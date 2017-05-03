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
	unsigned int				currentCard = 0;

	/*
	 * Executes the given instruction, updating currentPos and currentCard
	 */
	void						ExecuteInstruction(const Instruction& instruction);

public:
								TuringMachine();
                                TuringMachine(std::vector<Card> cards_in, std::list<bool> memory_in);
								TuringMachine(const TuringMachine& other) = delete; // Can't copy this atm
								TuringMachine& operator=(const TuringMachine& other) = delete; // Can't copy this atm
								TuringMachine(TuringMachine&& other);
								TuringMachine& operator=(TuringMachine&& other); // if you have a move ctor, you should also have a move assignment operator
	
	/*
	 * Ticks the simulation forward by executing the next instruction
	 */
	void						Tick();

	/*
	 * Peeks at the memory of the TuringMachine
	 */
	const std::list<bool>&		PeekMemory();

private:
};
