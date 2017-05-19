#pragma once

#include <vector>
#include <set>
#include <algorithm>
#include <Windows.h>

#include "DataManager.hh"


class Table
{
private:

	// Attributes

	DataManager & dataManager;

	std::vector<std::string> elements;

public:

	// Constructors

	Table(DataManager & gameManager);

	// Getters

	int getElementsSize();

	std::string getElement(int index);

	// Methods

	void createElement(Combination combination, std::string & check);

	void addElement(std::string name);

	void deleteElement(std::string name);

	void Table::deleteElement(int index);

	void addBasics();

	void sort();

	void clean();

	void info(int index);


	void draw();
};
