#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
# include <string>
# include <iostream>

using std::string;
using std::cout;
using std::endl;


class WrongCat : public WrongAnimal
{
protected:
	string type;
public:
	WrongCat();
	WrongCat(const WrongCat &toCopy);
	WrongCat& operator=(const WrongCat &tocopy);
	~WrongCat();
	void makeSound() const;
	string getType() const;
};
#endif
