#include "DataManager.hh"
#include "Player.hh"
#include "table.hh"


void drawTitle()
{
	std::cout << "--------------------------" << std::endl;
	std::cout << "    FULLENTI ALCHEMIST" << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << std::endl;
}

void main()
{
	DataManager dataManager;
	Table table(dataManager);
	Player player(table);

	drawTitle();
	player.help();
	std::cout << "Your current score: " << player.getScore() << std::endl;
	table.draw();

	while (true)
	{
		std::string input1;
		std::string input2;
		
		std::string buffer;
		std::cin >> buffer;

		system("cls");

		drawTitle();

		const char SPACER = '/';

		bool spaced = false;
		
		std::string command;
		int i = 0;
		while (i < buffer.size())
		{
			if (buffer[i] == SPACER)
			{
				spaced = true;
			}
			i++;
		}

		if (!spaced)
		{
			command = buffer;
			if (command == "sort")
			{
				player.sort();
			}
			else if (command == "clean")
			{
				player.clean();
			}
			else if (command == "help")
			{
				player.help();
			}
			else
			{
				std::cout << "Write 'info' to check valid commands!" << std::endl;
			}
		}
		else
		{
			int j = 0;
			while (buffer[j] != SPACER)
			{
				command.push_back(buffer[j]);
				j++;
			}

			j++;

			std::string extraCommand;
			while (j < buffer.size())
			{
				extraCommand.push_back(buffer[j]);
				j++;
			}

			if (command == "add")
			{
				if (extraCommand == "basics")
				{
					player.addBasics();
				}
				else
				{
					player.addElement(extraCommand);
				}
			}
			else if (command == "delete")
			{
				int value = atoi(extraCommand.c_str());
				player.deleteElement(value-1);
			}
			else if (command == "info")
			{
				std::cout << "ENTRA";
				int value = atoi(extraCommand.c_str());
				player.info(value);
			}
			else
			{
				if (command != extraCommand)
				{
					int valueCommand = atoi(command.c_str());
					int valueExtraCommand = atoi(extraCommand.c_str());

					bool a = (valueCommand > 0 && valueCommand <= table.getElementsSize());
					bool b = (valueExtraCommand > 0 && valueExtraCommand <= table.getElementsSize());

					if (a && b)
					{
						std::string firstElement = table.getElement(valueCommand - 1);
						std::string secondElement = table.getElement(valueExtraCommand - 1);

						Combination combination(firstElement, secondElement);
						player.createElement(combination);
					}
					else
					{
						std::cout << "You have to use the current elements on the table!" << std::endl;
					}


				}
				else
				{
					std::cout << "You must select 2 different elements!" << std::endl;
				}
			}
		}

		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		
		std::cout << "Your current score: " << player.getScore() << std::endl;
		table.draw();
	}
}
