#include <iostream>
#include <cctype>

#include "Card.h"

void Card::printEmptyError()
{
	std::cerr << "Card is empty" << std::endl;
}

void Card::printDuplicateError()
{
	std::cerr << "Card is duplicate" << std::endl;
}

Card::Card(char fSide) : frontSide {fSide}
{
	backSide = '*';
	hidden = true;
}

char Card::getFrontSide() const
{
	return frontSide;
}

void Card::setFrontSide(char fSide)
{
	frontSide = fSide;
}

void Card::show()
{
	hidden = false;
}

void Card::hide()
{
	hidden = true;
}

void Card::print() const
{
	std::cout << (hidden ? backSide : frontSide);
}

bool Card::isEmpty() const
{
	return std::isspace(frontSide) && std::isspace(backSide);
}

bool Card::isDuplicate(const Card& card) const
{
	return this == &card;
}

bool Card::isMatch(Card& card)
{
	if(frontSide == card.frontSide)
	{
		std::cout << "Match!" << std::endl;
		remove();
		card.remove();

		return true;
	}

	return false;
}

void Card::remove()
{
	frontSide = ' ';
	backSide = ' ';
}