#include "Instruction.hpp"

Instruction::Instruction() 
{
	moveType = MoveType::STAY;
	overwrite = 0;
	nextCard = 0;
}

Instruction::Instruction(MoveType m, bool o, unsigned int n) 
{
	moveType = m;	
	overwrite = o;
	nextCard = n;
}

Instruction::Instruction(const Instruction& other) 
{
	moveType = other.moveType;	
	overwrite = other.overwrite;
	nextCard = other.nextCard;
}

Instruction::Instruction(Instruction&& other) 
{
	moveType = other.moveType;	
	overwrite = other.overwrite;
	nextCard = other.nextCard;
}

void Instruction::operator=(const Instruction& other)
{
	moveType = other.moveType;	
	overwrite = other.overwrite;
	nextCard = other.nextCard;
}