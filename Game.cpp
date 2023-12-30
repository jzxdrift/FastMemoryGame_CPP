#include <iostream>
#include <cstddef>

#include "Card.h"
#include "Board.h"
#include "Utility.h"

void startGame()
{
	Board board;
	board.shuffle();

	while(!board.isSolved())
	{
		std::size_t input, otherInput;

		board.print();

		bool cardEmpty {false};
		do
		{
			input = getInput();
			input = convertToIndex(input);

			if(!(cardEmpty = board.getCards()[input].isEmpty()))
				const_cast<std::vector<Card>&>(board.getCards())[input].show();
			else
				Card::printEmptyError();

			std::cout << std::endl;
			board.print();

		} while(cardEmpty);

		bool cardDuplicate {false};
		do
		{
			otherInput = getInput();
			otherInput = convertToIndex(otherInput);

			if(!(cardEmpty = board.getCards()[otherInput].isEmpty()))
			{
				if(!(cardDuplicate = board.getCards()[input]
					.isDuplicate(board.getCards()[otherInput])))
					const_cast<std::vector<Card>&>(board.getCards())[otherInput].show();
				else
					Card::printDuplicateError();
			}
			else
				Card::printEmptyError();

			std::cout << std::endl;
			board.print();

		} while(cardEmpty || cardDuplicate);

		if(!const_cast<std::vector<Card>&>(board.getCards())[input]
			.isMatch(const_cast<std::vector<Card>&>(board.getCards())[otherInput]))
		{
			const_cast<std::vector<Card>&>(board.getCards())[input].hide();
			const_cast<std::vector<Card>&>(board.getCards())[otherInput].hide();
		}

		clearScreen();
	}
}