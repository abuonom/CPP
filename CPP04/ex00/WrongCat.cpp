#include "WrongCat.hpp"

WrongCat::WrongCat(/* args */)
{
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &toCopy) : WrongAnimal(toCopy)
{
	if(this != &toCopy)
		*this = toCopy;
	cout<<"WrongCat created with copy constructor"<<endl;
}

WrongCat& WrongCat::operator=(const WrongCat &tocopy)
{
	this->type = tocopy.type;
	return *this;
}

WrongCat::~WrongCat()
{
}

void WrongCat::makeSound() const
{
	cout<<"Meow Meow"<<std::endl;
}

string WrongCat::getType() const
{
	return this->type;
}
