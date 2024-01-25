#include "WrongCat.hpp"

WrongCat::WrongCat(/* args */)
{
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &toCopy) : WrongAnimal(toCopy)
{
	if(this != &toCopy)
		*this = toCopy;
	std::cout<<"WrongCat created with copy constructor"<<std::endl;
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
	std::cout<<"Meow Meow"<<std::endl;
}

string WrongCat::getType() const
{
	return this->type;
}
