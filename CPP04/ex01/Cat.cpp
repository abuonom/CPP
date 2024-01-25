#include "Cat.hpp"

Cat::Cat(/* args */)
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat created with default constructor" << std::endl;
}

Cat::Cat(const Cat &toCopy) : Animal(toCopy)
{
	this->brain = new Brain(*toCopy.brain);
	std::cout << "Cat created with copy constructor" << std::endl;
}

// Operatore di assegnazione profonda
Cat &Cat::operator=(const Cat &tocopy)
{
	// Verifica l'autoassegnazione
	if (this != &tocopy)
	{
		// Dealloca la memoria esistente di brain
		delete this->brain;

		// Effettua una deep copy di Brain
		this->brain = new Brain(*tocopy.brain);

		// Copia gli altri membri
		this->type = tocopy.type;
	}
	return *this;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}

std::string Cat::getType() const
{
	return this->type;
}

Brain *Cat::getBrain() const
{
	return brain;
}
