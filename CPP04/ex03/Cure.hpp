#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
private:

public:
	Cure();
	Cure(const Cure &toCopy);
	Cure& operator=(const Cure &tocopy);
	~Cure();
	void use(ICharacter& target);
	AMateria* clone() const;
};

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

#endif // MACRO

