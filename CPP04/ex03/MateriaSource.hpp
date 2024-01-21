#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *inventory[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &toCopy);
	MateriaSource &operator=(const MateriaSource &tocopy);
	~MateriaSource();
	void learnMateria(AMateria *);
	AMateria *createMateria(std::string const &type);
};

MateriaSource::MateriaSource(/* args */)
{
}

MateriaSource::MateriaSource(const MateriaSource &toCopy)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (inventory[i] != 0)
			inventory[i] = toCopy.inventory[i]->clone();
		else
			inventory[i] = 0;
	}
	cout << "MateriaSource created with copy constructor" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &toCopy)
{
	if (this != &toCopy)
	{
		for (size_t i = 0; i < 4; i++)
		{
			if (inventory[i] != 0)
				delete inventory[i];
			if (inventory != 0)
				inventory[i] = toCopy.inventory[i]->clone();
			else
				inventory[i] = 0;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
}

void MateriaSource::learnMateria(AMateria *mat)
{
	int i;
	if (mat == 0)
	{
		std::cout << "Really man? You want to learn by the ancient scrolls of NULL? " << std::endl;
		return;
	}
	for (i = 0; i < 4; i++)
	{
		if (inventory[i] == 0)
			break;
	}
	if (i == 4)
	{
		std::cout << "The MateriaSource is full" << std::endl;
		return;
	}
	this->inventory[i] == mat;
	return ;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (inventory[i] != 0 && type == inventory[i]->getType())
			return inventory[i]->clone();
	}
	std::cout << "Missing Materia Type" << std::endl;
	return 0;
}

#endif
