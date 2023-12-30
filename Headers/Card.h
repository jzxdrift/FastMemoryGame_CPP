#pragma once

class Card
{
public:
	static void printEmptyError();
	static void printDuplicateError();

public:
	explicit Card(char);

	char getFrontSide() const;
	void setFrontSide(char);

	void show();
	void hide();

	void print() const;

	bool isEmpty() const;
	bool isDuplicate(const Card&) const;
	bool isMatch(Card&);

private:
	void remove();

private:
	char frontSide;
	char backSide;
	bool hidden;
};
