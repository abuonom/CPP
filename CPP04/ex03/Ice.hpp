#ifndef ICE_HPP
# define ICE_HPP
#include "AMateria.hpp"

class Ice : public AMateria
{
private:

public:
	Ice();
	Ice(const Ice &toCopy);
	Ice& operator=(const Ice &tocopy);
	~Ice();
	void use(ICharacter& target);
	AMateria* clone() const;
};

Ice::Ice() : AMateria("Ice")
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

#endif // MACRO
