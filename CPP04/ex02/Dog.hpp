#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"
#include  "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* brain;
protected:
	string type;
public:
	Dog();
	Dog(const Dog &toCopy);
	Dog& operator=(const Dog &tocopy);
	~Dog();
	void makeSound() const;
	string getType() const;
	Brain* getBrain() const;
};

#endif
