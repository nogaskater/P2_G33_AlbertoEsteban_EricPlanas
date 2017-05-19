#pragma once

#include<string>

class Combination
{
private:

	// Attributes

	std::string element1;
	std::string element2;

public:

	// Constructors

	Combination();

	Combination(std::string element1, std::string element2);

	Combination(const Combination & other);

	// Getters

	std::string getElement1();

	std::string getElement2();

	// Methods

	bool operator==(const Combination &other) const;

	size_t operator()(const Combination &c) const;
};