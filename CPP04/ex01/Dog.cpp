#include "Dog.hpp"

Dog::Dog(/* args */)
{
	this->type = "Dog";
	this->brain = new Brain();
	cout << "Dog created with default constructor" << endl;
}

// Costruttore di copia profonda
Dog::Dog(const Dog &toCopy) : Animal(toCopy)
{
	this->brain = new Brain(*toCopy.brain);
	cout << "Dog created with copy constructor" << endl;
}

// Operatore di assegnazione profonda
Dog &Dog::operator=(const Dog &tocopy)
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

Dog::~Dog()
{
	delete brain;
	cout << "Dog destructor called" << endl;
}

void Dog::makeSound() const
{
	cout << "Bau Bau" << std::endl;
}

string Dog::getType() const
{
	return this->type;
}

Brain *Dog::getBrain() const
{
	return brain;
}
