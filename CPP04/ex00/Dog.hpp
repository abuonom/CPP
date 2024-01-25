#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
protected:
	std::string type;
public:
	Dog();
	Dog(const Dog &toCopy);
	Dog& operator=(const Dog &tocopy);
	~Dog();
	void makeSound() const;
	string getType() const;
};

#endif
