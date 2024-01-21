#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	AMateria *inventory[4];
	AMateria *floor[200];
	std::string name;

public:
	Character(std::string name);
	Character(const Character &toCopy);
	Character &operator=(const Character &toCopy);
	~Character();
	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
	void cleanFloor();
};

Character::Character(std::string name)
{
	for (size_t i = 0; i < 4; i++)
		inventory[i] = 0;
	for (size_t i = 0; i < 200; i++)
		floor[i] = 0;
	this->name = name;
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
		return ;
	}
	inventory[i] == m;
}

void Character::unequip(int idx)
{
	size_t i;
	if (inventory[idx] == 0)
	{
		std::cout << "You can't use a materia that not exist..." << std::endl;
		return ;
	}
	for (i = 0; i < 200; i++)
	{
		if (floor[i] == 0)
			break;
	}
	if (i == 200)
	{
		std::cout << "I can't unequip, we need to clean the floor first..." << std::endl;
		return ;
	}
	else
	{
		floor[i] = inventory[idx];
		inventory[idx] = 0;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if(inventory[idx] == 0 || idx > 3)
	{
		std::cout<<name<<" have not a Materia at position "<<idx<<" of his inventory\n";
		return ;
	}
	inventory[idx]->use(target);
}

void Character::cleanFloor()
{
	for (size_t i = 0; i < 200; i++)
		delete floor[i];
}

#endif
