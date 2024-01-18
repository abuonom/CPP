#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const DiamondTrap &toCopy) : ClapTrap(toCopy), ScavTrap(toCopy), FragTrap(toCopy)
{
	if(this != &toCopy)
		*this = toCopy;
	std::cout<<"DiamondTrap "<<this->name<<" has been created with copy constructor"<<std::endl;
	return;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &toCopy)
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

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),ScavTrap(name) , FragTrap(name)
{
	this->name = name;
	std::cout<<"DiamondTrap "<<name<<" created with default constructor"<<std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout<<"DiamondTrap "<<name<<"destroyed"<<std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout<<"Who am i? I'm "<<name<<" but my real name is "<<ClapTrap::name<<std::endl;
}
