#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

using std::string;
using std::cout;
using std::endl;


class Animal
{
protected:
	string type;
public:
	Animal();
	Animal(const Animal &toCopy);
	Animal& operator=(const Animal &tocopy);
	virtual ~Animal();
	virtual void makeSound() const = 0;
	virtual string getType() const;
};
#endif
