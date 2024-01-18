#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:

public:
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(const ScavTrap &toCopy);
	ScavTrap& operator=(const ScavTrap &tocopy);
	void	attack(const std::string& target);
	void 	guardGate();
};

#endif


