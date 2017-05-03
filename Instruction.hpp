#pragma once

enum class MoveType
{
	LEFT, // Move left on the next instruction
	RIGHT, // Move right on the next instruction
	STAY // Stay here on the next instruction
};

/*
 * Represents an instruction in the Turing Machine. 
 * Tells what to do. A card has two instructions on it
 */
class Instruction 
{
public:
					Instruction() = default;
					Instruction(MoveType m, bool o, unsigned int n);
                    // As long as you don't do anything to make it impossible, (const or ref members)
                    // the compiler will generate copy ctor and copy assignment operator for you, so no need for explicit ones
                    // Also no need for move ctor unless you semantically want class to be noncopyable,
                    // or if it contains members that are expensive to copy
                    // So get rid of that too

	MoveType 		moveType = MoveType::STAY; 		// How to move the pointer next time around
	bool 			overwrite = false;	 	// What to overwrite the current place with
	unsigned int 	nextCard = 0; 		// What next card to go to
};
