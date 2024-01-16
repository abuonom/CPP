#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name)
{
	this->attackDamage = 20;
	this->energyPoint = 50;
	this->hitPoint = 100;
	std::cout<<"ClapTrap "<<this->name<<" has been created with default constructor"<<std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &toCopy)
{
	*this = toCopy;
	std::cout<<"ClapTrap "<<this->name<<" has been created with copy constructor"<<std::endl;
	return;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &toCopy)
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

ClapTrap::~ClapTrap()
{
	std::cout<<"ClapTrap "<<this->name<<" has been destroyed"<<std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if(energyPoint >= 1 && hitPoint != 0)
	{
		this->energyPoint--;
		std::cout<<"ClapTrap "<<this->name<<" attacks "<<target<<", causing "<<this->attackDamage<<std::endl;
	}
	else if(hitPoint == 0)
			std::cout<<"ClapTrap "<<this->name<< "is dead"<<std::endl;
		else
			std::cout<<"ClapTrap "<<this->name<< "has not energy left for attack"<<std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	hitPoint -= amount;
	if(hitPoint > 0)
		std::cout<<"ClapTrap "<<this->name<<" has taken "<<amount<<". Hit point lefts: "<<hitPoint<<std::endl;
	else
	{
		hitPoint = 0;
		std::cout<<"ClapTrap "<<this->name<<" is dead "<<hitPoint<<std::endl;
	}

}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if(energyPoint >= 1 && hitPoint != 0)
	{
		this->energyPoint--;
		hitPoint += amount;
		std::cout<<"ClapTrap "<<name<<" repair itself "<<amount<<". New hit points: "<<hitPoint<<std::endl;
	}
	else if(hitPoint == 0)
			std::cout<<"ClapTrap "<<this->name<< "is dead"<<std::endl;
		else
			std::cout<<"ClapTrap "<<this->name<< "has not energy left for repair itself"<<std::endl;
}

std::string ClapTrap::getName()
{
	return name;
}
