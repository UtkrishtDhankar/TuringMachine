#include "TuringMachine.hpp"

TuringMachine::TuringMachine()
{

}

TuringMachine::TuringMachine(std::vector<Card> cards_in) : 
	cards(cards_in)
{

}

TuringMachine::TuringMachine(const TuringMachine& other)
{
	cards = other.cards;
}

TuringMachine::TuringMachine(TuringMachine&& other)
{
	cards = std::move(other.cards);
}
