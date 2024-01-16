#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout<<"ScavTrap "<<this->name<<" has been created with default constructor"<<std::endl;
	return;
}

ScavTrap::ScavTrap(const ScavTrap &toCopy) : ClapTrap(toCopy)
{
	std::cout<<"ScavTrap "<<this->name<<" has been created with copy constructor"<<std::endl;
	return;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &toCopy)
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

ScavTrap::~ScavTrap()
{
		std::cout<<"ScavTrap "<<this->name<<" has been destroyed"<<std::endl;
}

void ScavTrap::guardGate()
{
	std::cout<<"ScavTrap "<<name<<" is now in Gate keeper mode."<<std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if(energyPoint >= 1 && hitPoint != 0)
	{
		this->energyPoint--;
		std::cout<<"ScavTrap "<<this->name<<" attacks "<<target<<", causing "<<this->attackDamage<<std::endl;
	}
	else if(hitPoint == 0)
			std::cout<<"ScavTrap "<<this->name<< " is dead"<<std::endl;
		else
			std::cout<<"ScavTrap "<<this->name<< " has not energy left for attack"<<std::endl;
}
