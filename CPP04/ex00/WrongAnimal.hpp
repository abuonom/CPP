#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &toCopy);
	WrongAnimal& operator=(const WrongAnimal &tocopy);
	~WrongAnimal();
	void makeSound() const;
	string getType() const;
};
#endif
