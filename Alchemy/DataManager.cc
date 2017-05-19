#include "DataManager.hh"

void DataManager::fill()
{
	std::ifstream file;
	std::ifstream checkFile(FILE_NAME);
	
	if(checkFile.good())
		file.open(FILE_NAME);
	else
	{
		std::cout << "The file " + FILE_NAME + " was not loaded correctly!\n" << std::endl;
		system("pause");
	}


	std::string linea;

	while (getline(file, linea))
	{
		std::string value;
		std::string element1;
		std::string element2;

		int i = 0;

		while (linea[i] != '=')
		{
			value.push_back(linea[i]);

			i++;
		}

		value.pop_back();

		i += 2;

		while (linea[i] != '+')
		{
			element1.push_back(linea[i]);

			i++;
		}

		element1.pop_back();

		i += 2;

		while (i < linea.length())
		{
			element2.push_back(linea[i]);

			i++;
		}

		Combination key(element1, element2);

		std::pair<Combination, std::string> pair(key, value);

		map.insert(pair);
	};
}

DataManager::DataManager()
{
	fill();
}

std::string DataManager::getValue(Combination combination)
{
	auto it = map.find(combination);

	if (it != map.end())
	{
		return map[combination];
	}

	Combination combination2(combination.getElement2(), combination.getElement1());
	it = map.find(combination2);

	if (it != map.end())
	{
		return map[combination2];
	}

	return "not_found";
}

void DataManager::draw()
{
	for (auto it = map.begin(); it != map.end(); ++it)
	{
		Combination comb(it->first);

		std::cout << comb.getElement1() << " " << comb.getElement2() << " " << it->second << std::endl;
	}
}
