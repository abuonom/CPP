#include "Character.hpp"

Character::Character(std::string name)
{
	for (size_t i = 0; i < 4; i++)
		inventory[i] = 0;
	for (size_t i = 0; i < 200; i++)
		floor[i] = 0;
	this->name = name;
	cout<<"Character "<<this->name<<" created with default constructor\n"<<std::endl;
}

// Costruttore di copia profonda
Character::Character(const Character &toCopy)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (inventory[i] != 0)
			inventory[i] = toCopy.inventory[i]->clone();
		else
			inventory[i] = 0;
	}
	for (size_t i = 0; i < 200; i++)
	{
		if (floor[i] != 0)
			floor[i] = toCopy.floor[i]->clone();
		else
			floor[i] = 0;
	}

	cout << "Character created with copy constructor" << std::endl;
}

// Operatore di assegnazione profonda
Character &Character::operator=(const Character &toCopy)
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
		for (size_t i = 0; i < 200; i++)
		{
			if (floor[i] != 0)
				delete floor[i];
			if (floor[i] != 0)
				floor[i] = toCopy.floor[i]->clone();
			else
				floor[i] = 0;
		}
	}
	return *this;
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
		delete inventory[i];
	for (size_t i = 0; i < 200; i++)
		delete floor[i];
	std::cout << "Character " << this->name << " destruct" << std::endl;
}

std::string const &Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria *m)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (inventory[i] == 0)
			break;
	}
	if (i == 4)
	{
		std::cout << "The inventory of " << this->name << " is full" << std::endl;
		return;
	}
	inventory[i] = m;
	std::cout<<"Character "<<this->name<< " has equipped "<<m->getType()<<" on slot "<<i<<"\n"<<std::endl;
}

void Character::unequip(int idx)
{
	size_t i;
	if (inventory[idx] == 0)
	{
		std::cout << "You can't unequip a materia that not exist..." << std::endl;
		return;
	}
	for (i = 0; i < 200; i++)
	{
		if (floor[i] == 0)
			break;
	}
	if (i == 200)
	{
		std::cout << "I can't unequip, we need to clean the floor first..." << std::endl;
		return;
	}
	else
	{
		floor[i] = inventory[idx];
		std::cout<<"Materia "<<inventory[idx]->getType()<< " dropped on floor"<<std::endl;
		inventory[idx] = 0;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (inventory[idx] == 0 || idx > 3)
	{
		std::cout << name << " have not a Materia at position " << idx << " of his inventory\n";
		return;
	}
	inventory[idx]->use(target);
}

void Character::cleanFloor()
{
	for (size_t i = 0; i < 200; i++)
		delete floor[i];
}
