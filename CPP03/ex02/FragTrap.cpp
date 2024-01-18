#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitPoint = 100;
	energyPoint = 100;
	attackDamage = 100;
	std::cout<<"FragTrap "<<this->name<<" has been created with default constructor"<<std::endl;
	return;
}

FragTrap::FragTrap(const FragTrap &toCopy) : ClapTrap(toCopy)
{
	if(this != &toCopy)
		*this = toCopy;
	std::cout<<"FragTrap "<<this->name<<" has been created with copy constructor"<<std::endl;
	return;
}

FragTrap& FragTrap::operator=(const FragTrap &toCopy)
{
	if(this != &toCopy)
	{
		this->name = toCopy.name;
		this->attackDamage = toCopy.attackDamage;
		this->energyPoint = toCopy.energyPoint;
		this->hitPoint = toCopy.hitPoint;
	}
	return *this;
}

FragTrap::~FragTrap()
{
		std::cout<<"FragTrap "<<this->name<<" has been destroyed"<<std::endl;
}

void		FragTrap::highFivesGuys(void)
{
	std::cout << "Scavtrap \"Hey, Vault Hunter! Gimme a high five! Or, you know, just a regular five... I'm not picky!\"" << std::endl;
}
