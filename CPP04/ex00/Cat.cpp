#include "Cat.hpp"

Cat::Cat(/* args */)
{
	this->type = "Cat";
}

Cat::Cat(const Cat &toCopy) : Animal(toCopy)
{
	if(this != &toCopy)
		*this = toCopy;
	std::cout<<"Cat created with copy constructor"<<endl;
}

Cat& Cat::operator=(const Cat &tocopy)
{
	this->type = tocopy.type;
	return *this;
}

Cat::~Cat()
{
	std::cout<<"Cat destructor called"<<endl;
}

void Cat::makeSound() const
{
	std::cout<<"Meow Meow"<<std::endl;
}

string Cat::getType() const
{
	return this->type;
}
