#include "Card.hpp"

Card::Card(const Instruction& i0, const Instruction& i1)
    : instructions{i0, i1} // use initializer list for initialization
{
}
