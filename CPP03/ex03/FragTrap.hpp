#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
private:

public:
	FragTrap(std::string name);
	FragTrap(const FragTrap &toCopy);
	FragTrap&	operator=(const FragTrap &tocopy);
	void		highFivesGuys(void);
	~FragTrap();
};

#endif
