#include "Combination.hh"

Combination::Combination()
{

}

Combination::Combination(std::string element1, std::string element2) : element1(element1), element2(element2)
{

}

Combination::Combination(const Combination & other) : element1(other.element1), element2(other.element2)
{

}

std::string Combination::getElement1()
{
	return element1;
}

std::string Combination::getElement2()
{
	return element2;
}

bool Combination::operator==(const Combination &other) const
{
	return(element1 == other.element1 && element2 == other.element2);
}

size_t Combination::operator()(const Combination & c) const
{
	return ((std::hash<std::string>()(c.element1) ^ (std::hash<std::string>()(c.element2) << 1)) >> 1);
}

