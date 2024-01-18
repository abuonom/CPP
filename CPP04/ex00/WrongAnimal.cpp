#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(/* args */)
{
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &toCopy)
{
	if(this != &toCopy)
		*this = toCopy;
	cout<<"WrongAnimal created with copy constructor"<<endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &tocopy)
{
	this->type = tocopy.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	cout<<this->type<<" destroyed"<<endl;
}

void WrongAnimal::makeSound() const
{
	cout<<"What Does the Fox Say?"<<std::endl;
}

string WrongAnimal::getType() const
{
	return this->type;
}
