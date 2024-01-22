#include "Cat.hpp"

Cat::Cat(/* args */)
{
	this->type = "Cat";
}

Cat::Cat(const Cat &toCopy) : Animal(toCopy)
{
	if(this != &toCopy)
		*this = toCopy;
	cout<<"Cat created with copy constructor"<<endl;
}

Cat& Cat::operator=(const Cat &tocopy)
{
	this->type = tocopy.type;
	return *this;
}

Cat::~Cat()
{
	cout<<"Cat destructor called"<<endl;
}

void Cat::makeSound() const
{
	cout<<"Meow Meow"<<std::endl;
}

string Cat::getType() const
{
	return this->type;
}
