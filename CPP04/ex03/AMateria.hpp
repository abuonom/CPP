#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

using std::string;
using std::cout;

class AMateria
{
protected:
	std::string type;
public:
	AMateria(std::string const & type);
	AMateria(const AMateria &toCopy);
	AMateria& operator=(const AMateria &tocopy);
	virtual ~AMateria();
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

AMateria::AMateria(std::string const & type)
{
	this->type = type;
}

AMateria::AMateria(const AMateria &toCopy)
{
	this->type = toCopy.type;
	cout<<"AMateria created with copy constructor"<<std::endl;
}

AMateria& AMateria::operator=(const AMateria &tocopy)
{
	if(this != &tocopy)
	{
		this->type = tocopy.type;
	}
	return *this;
}

AMateria::~AMateria()
{
}

string const &AMateria::getType() const
{
	return this->type;
}

#endif


