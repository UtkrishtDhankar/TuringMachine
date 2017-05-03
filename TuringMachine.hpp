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
	unsigned int				currentCard;

	/*
	 * Initializes the memory of the TuringMachine.
	 */
	void						InitializeMemory();

	/*
	 * Executes the given instruction, updating currentPos and currentCard
	 */
	void						ExecuteInstruction(const Instruction& instruction);

public:
								TuringMachine();
								TuringMachine(std::vector<Card> cards);
								TuringMachine(const TuringMachine& other) = delete; // Can't copy this atm
								TuringMachine(TuringMachine&& other);
	
	/*
	 * Ticks the simulation forward by executing the next instruction
	 */
	void						Tick();

	/*
	 * Peaks at the memory of the TuringMachine
	 */
	const std::list<bool>&		PeakMemory();
};