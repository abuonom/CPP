#include "Materia.hpp"
#include "Character.hpp"

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

void AMateria::use(ICharacter &target)
{
	std::cout<<"* Using "<<this->type<<" materia on "<<target.getName()<< " *"<<std::endl;
}

AMateria::~AMateria()
{
}

string const &AMateria::getType() const
{
	return this->type;
}

Cure::Cure() : AMateria("cure")
{
	std::cout<<"Cure created with default constructor"<<std::endl;
}

Cure::Cure(const Cure &toCopy) : AMateria(toCopy)
{
	std::cout<<"Cure created with copy constructor"<<std::endl;
}

Cure& Cure::operator=(const Cure &tocopy)
{
	if(this != &tocopy)
	{
		AMateria::operator=(tocopy);
	}
	return *this;
}

Cure::~Cure()
{
	std::cout<<"Cure destroyed"<<std::endl;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout<<"* heals "<<target.getName()<< "'s wounds *"<<std::endl;
}

Ice::Ice() : AMateria("ice")
{
	std::cout<<"Ice created with default constructor"<<std::endl;
}

Ice::Ice(const Ice &toCopy) : AMateria(toCopy)
{
	std::cout<<"Ice created with copy constructor"<<std::endl;
}

Ice& Ice::operator=(const Ice &tocopy)
{
	if(this != &tocopy)
	{
		AMateria::operator=(tocopy);
	}
	return *this;
}

Ice::~Ice()
{
	std::cout<<"Ice destroyed"<<std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout<<"* shoots an ice bolt at "<<target.getName()<<" *"<<std::endl;
}

