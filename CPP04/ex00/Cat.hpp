#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
protected:
	std::string type;
public:
	Cat();
	Cat(const Cat &toCopy);
	Cat& operator=(const Cat &tocopy);
	~Cat();
	void makeSound() const;
	string getType() const;
};
#endif
