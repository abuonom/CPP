#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal &toCopy);
	Animal& operator=(const Animal &tocopy);
	virtual ~Animal();
	virtual void makeSound() const;
	virtual string getType() const;
};
#endif
