#include "Zombie.hpp"


Zombie::Zombie()
{

}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout<<name<<" joined evil\n";
}

Zombie::~Zombie()
{
	std::cout<<name<<" is back underground\n";
}

void Zombie::announce()
{
	std::cout<<this->name<<": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name)
{
	this->name = name;
}
