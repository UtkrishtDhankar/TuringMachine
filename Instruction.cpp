#include "Instruction.hpp"

Instruction::Instruction(MoveType m, bool o, unsigned int n) 
    : moveType(m), overwrite(o), nextCard(n)
    // When initializing in constructor (as opposed to direct member initialization
    // like I did elsewhere 
    // prefer the initialization list instead of ctor body
{
}

