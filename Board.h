#pragma once

#include <cstddef>
#include <vector>

#include "Card.h"

class Board
{
public:
	Board();

	const std::vector<Card>& getCards() const;

	void shuffle();
	void print() const;

	bool isSolved() const;

private:
	const std::size_t ROWS {6}, COLS {6};

	mutable std::vector<Card> cards;
};