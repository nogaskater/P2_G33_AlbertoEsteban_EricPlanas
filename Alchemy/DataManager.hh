#pragma once

#include <fstream> 
#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include"Combination.hh"

class DataManager
{
private:

	// Consts

	const std::string FILE_NAME = "elements.dat";

	// Attributes

	std::unordered_map<Combination, std::string, Combination> map;

	// Methods

	void fill();

public:

	// Constructors

	DataManager();

	// Getter

	std::string getValue(Combination combination);

	// Methods

	void draw();
};
