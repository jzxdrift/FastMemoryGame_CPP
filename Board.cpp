#include <iostream>
#include <cstddef>
#include <algorithm>
#include <random>

#include "Card.h"
#include "Board.h"

Board::Board()
{
	Card tempCard {'A'};

	for(std::size_t i {0}; i < ROWS * COLS; i += 2)
	{
		cards.push_back(tempCard);
		cards.push_back(tempCard);
		tempCard.setFrontSide(tempCard.getFrontSide() + 1);
	}
}

const std::vector<Card>& Board::getCards() const
{
	return cards;
}

void Board::shuffle()
{
	std::shuffle(cards.begin(), cards.end(),
		std::default_random_engine {std::random_device {}()});
}

void Board::print() const
{
	std::cout << "  ";

	for(std::size_t i {1}; i <= COLS; ++i)
		std::cout << i << ' ';
	std::cout << std::endl;

	for(std::size_t i {0}, j {0}; i < ROWS; ++i, j += COLS)
	{
		std::cout << i + 1 << ' ';

		for(std::size_t k {j}; k < COLS + j; ++k)
		{
			cards[k].print();
			std::cout << ' ';
		}

		std::cout << std::endl;
	}
}

bool Board::isSolved() const
{
	for(const Card& card : cards)
	{
		if(!card.isEmpty())
			return false;
	}
	std::cout << "Game solved!" << std::endl;

	return true;
}