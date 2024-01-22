#include "Animal.hpp"

Animal::Animal(/* args */)
{
	this->type = "Animal";
}

Animal::Animal(const Animal &toCopy)
{
	if(this != &toCopy)
		*this = toCopy;
	cout<<"Animal created with copy constructor"<<endl;
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
	cout<<"What Does the Fox Say?"<<std::endl;
}

string Animal::getType() const
{
	return this->type;
}
