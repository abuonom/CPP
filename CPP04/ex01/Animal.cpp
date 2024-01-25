#include "Animal.hpp"

Animal::Animal(/* args */)
{
	this->type = "Animal";
}

Animal::Animal(const Animal &toCopy)
{
	if(this != &toCopy)
		*this = toCopy;
	std::cout<<"Animal created with copy constructor"<<std::endl;
}

Animal& Animal::operator=(const Animal &tocopy)
{
	this->type = tocopy.type;
	return *this;
}

Animal::~Animal()
{
}

void Animal::makeSound() const
{
	std::cout<<"What Does the Fox Say?"<<std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}
