#include "Table.hh"

Table::Table(DataManager & gameManager) : dataManager(gameManager), elements({ "Wind", "Fire", "Earth", "Water" })
{

}

int Table::getElementsSize()
{

	return elements.size();
}

std::string Table::getElement(int index)
{
	return elements[index];
}

void Table::createElement(Combination combination, std::string & check)
{
	std::string value = dataManager.getValue(combination);

	// If exists

	if (value != "not_found")
	{
		// Remove used elements

		for (int i = 0; i < elements.size(); i++)
		{
			if (elements[i] == combination.getElement1() || elements[i] == combination.getElement2())
			{
				elements.erase(elements.begin() + i);
			}
		}

		// Add new element

		elements.push_back(value);
	}

	check = value;
}

void Table::addElement(std::string name)
{
	elements.push_back(name);
}

void Table::deleteElement(std::string name)
{
	for (int i = 0; i < elements.size(); i++)
	{
		if (elements[i] == name)
		{
			elements.erase(elements.begin() + i);
		}
	}
}

void Table::deleteElement(int index)
{
	elements.erase(elements.begin() + index);
}

void Table::addBasics()
{
	elements.push_back("Wind");
	elements.push_back("Fire");
	elements.push_back("Earth");
	elements.push_back("Water");
}

void Table::sort()
{
	std::sort(elements.begin(), elements.end());
}

void Table::clean()
{
	std::set<std::string> s(elements.begin(), elements.end());

	elements.assign(s.begin(), s.end());
}

void Table::info(int index)
{
	std::string path = "https://en.wikipedia.org/wiki/" + elements[index];
	ShellExecuteA(nullptr, "open", path.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
}

void Table::draw()
{
	std::cout << "You have this elements on the table:" << std::endl;

	for (int i = 0; i < elements.size(); i++)
	{
		std::cout << i + 1 << ". " << elements[i] << std::endl;
	}
}
