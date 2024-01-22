#include "Dog.hpp"


Dog::Dog(/* args */)
{
	this->type = "Dog";
}

Dog::Dog(const Dog &toCopy) : Animal(toCopy)
{
	if(this != &toCopy)
		*this = toCopy;
	cout<<"Dog created with copy constructor"<<endl;
}

Dog& Dog::operator=(const Dog &tocopy)
{
	this->type = tocopy.type;
	return *this;
}

Dog::~Dog()
{
	cout<<"Dog destructor called"<<endl;
}

void Dog::makeSound() const
{
	cout<<"Bau Bau"<<std::endl;
}

string Dog::getType() const
{
	return this->type;
}
