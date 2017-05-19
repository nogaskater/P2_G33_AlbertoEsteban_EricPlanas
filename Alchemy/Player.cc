#include "Player.hh"


Player::Player(Table & table) : table(table), score(0)
{

}

int Player::getScore()
{
	return score;
}

void Player::createElement(Combination combination)
{
	std::string value;

	table.createElement(combination, value);

	// If exists

	if (value != "not_found")
	{
		// If not repeated

		bool isElement = false;

		for (int i = 0; i < inventory.size(); i++)
		{
			if (inventory[i] == value)
			{
				isElement = true;
			}
		}

		if (!isElement)
		{
			inventory.push_back(value);

			score++;

			std::cout << "You have found a new element! " + value + " added to your inventory!" << std::endl;
		}
		else
		{
			std::cout << "The element you found is already in your inventory!" << std::endl;
		}
	}
}

void Player::addElement(std::string name)
{
	for (int i = 0; i < inventory.size(); i++)
	{
		std::string elementName = inventory[i];

		if (elementName == name)
		{
			table.addElement(name);

			return;
		}
	}
	std::cout << "The element you asked for is not in your inventory!" << std::endl;
}

void Player::deleteElement(std::string name)
{
	table.deleteElement(name);
}

void Player::deleteElement(int index)
{
	table.deleteElement(index);
}

void Player::addBasics()
{
	table.addBasics();
}

void Player::sort()
{
	table.sort();
}

void Player::clean()
{
	table.clean();
}

void Player::info(int index)
{
	table.info(index);
}

void Player::help()
{
	std::cout << "- Enter two numbers of your elements list to combine them." << std::endl;
	std::cout << "- Enter the word 'add' and the number of an element to add a new instance of that element." << std::endl;
	std::cout << "- Enter 'add basics' to add instances of the 4 basic elements." << std::endl;
	std::cout << "- Enter the word 'delete' and the number of an element to erase it from your list." << std::endl;
	std::cout << "- Enter the word 'info' and the number of an element to get information about it in the explorer." << std::endl;
	std::cout << "- Enter the word 'sort' to sort by alphabetical order the elements in the list." << std::endl;
	std::cout << "- Enter the word 'clean' to delete all the instances of repeated elements." << std::endl;
	std::cout << "- Enter the word 'help' to show this tutorial." << std::endl;
	std::cout << std::endl;
}

