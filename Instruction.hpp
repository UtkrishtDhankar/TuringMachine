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
					Instruction();
					Instruction(MoveType m, bool o, unsigned int n);
					Instruction(const Instruction& other);
					Instruction(Instruction&& other);

	void			operator=(const Instruction& other);

	MoveType 		moveType; 		// How to move the pointer next time around
	bool 			overwrite;	 	// What to overwrite the current place with
	unsigned int 	nextCard; 		// What next card to go to
};