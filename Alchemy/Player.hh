#pragma once

#include<vector>

#include"Table.hh"

class Player
{
private:

	// Attributes

	Table & table;

	std::vector<std::string> inventory;

	int score;

public:

	// Constructors

	Player(Table & table);

	// Getters

	int getScore();

	// Methods

	void createElement(Combination combination);

	void addElement(std::string name);

	void deleteElement(std::string name);

	void deleteElement(int index);

	void addBasics();

	void sort();

	void clean();

	void info(int index);

	void help();
};