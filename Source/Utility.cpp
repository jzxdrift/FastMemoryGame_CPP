#include <iostream>
#include <cstddef>
#include <cstdlib>

static const int MIN {1}, MAX {6}, DIV {10};

static bool isValidRange(int);

std::size_t getInput()
{
	int input;

	bool valid {false};
	do
	{
		std::cout << "\nEnter row, then column in format XX: ";

		if(std::cin >> input && isValidRange(input))
			valid = true;
		else
			std::cerr << "Invalid input, try again" << std::endl;

		std::cin.clear();
		while(std::cin.get() != '\n');

	} while(!valid);

	return static_cast<std::size_t>(input);
}

std::size_t convertToIndex(std::size_t num)
{
	return (num / DIV - 1) * MAX + (num % DIV - 1);
}

void clearScreen()
{
	std::cout << "\nPress enter to continue...";
	std::cin.get();
	std::system("cls");
}

static bool isValidRange(int num)
{
	return (num / DIV >= MIN && num / DIV <= MAX)
		&& (num % DIV >= MIN && num % DIV <= MAX);
}
