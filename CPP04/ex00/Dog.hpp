#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"

using std::string;
using std::cout;
using std::endl;


class Dog : public Animal
{
protected:
	string type;
public:
	Dog();
	Dog(const Dog &toCopy);
	Dog& operator=(const Dog &tocopy);
	~Dog();
	void makeSound() const;
	string getType() const;
};

#endif
