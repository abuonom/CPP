#include "Dog.hpp"


Dog::Dog(/* args */)
{
	this->type = "Dog";
}

Dog::Dog(const Dog &toCopy) : Animal(toCopy)
{
	if(this != &toCopy)
		*this = toCopy;
	std::cout<<"Dog created with copy constructor"<<std::endl;
}

Dog& Dog::operator=(const Dog &tocopy)
{
	this->type = tocopy.type;
	return *this;
}

Dog::~Dog()
{
	std::cout<<"Dog destructor called"<<std::endl;
}

void Dog::makeSound() const
{
	std::cout<<"Bau Bau"<<std::endl;
}

string Dog::getType() const
{
	return this->type;
}
