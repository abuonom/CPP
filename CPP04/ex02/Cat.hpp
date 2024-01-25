#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain* brain;
protected:
	string type;
public:
	Cat();
	Cat(const Cat &toCopy);
	Cat& operator=(const Cat &tocopy);
	~Cat();
	void makeSound() const;
	string getType() const;
	Brain* getBrain() const;
};
#endif
