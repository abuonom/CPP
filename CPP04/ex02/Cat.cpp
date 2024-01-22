#include "Cat.hpp"

Cat::Cat(/* args */)
{
	this->type = "Cat";
	this->brain = new Brain();
	cout << "Cat created with default constructor" << endl;
}

Cat::Cat(const Cat &toCopy) : Animal(toCopy)
{
	this->brain = new Brain(*toCopy.brain);
	cout << "Cat created with copy constructor" << endl;
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
	cout << "Cat destructor called" << endl;
}

void Cat::makeSound() const
{
	cout << "Meow Meow" << std::endl;
}

string Cat::getType() const
{
	return this->type;
}

Brain *Cat::getBrain() const
{
	return brain;
}
