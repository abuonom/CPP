#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(/* args */)
{
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &toCopy)
{
	if(this != &toCopy)
		*this = toCopy;
	std::cout<<"WrongAnimal created with copy constructor"<<std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &tocopy)
{
	this->type = tocopy.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout<<this->type<<" destroyed"<<std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout<<"What Does the Fox Say?"<<std::endl;
}

string WrongAnimal::getType() const
{
	return this->type;
}
