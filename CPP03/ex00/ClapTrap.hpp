#ifndef CLAPTRAP_H
# define CLPATRAP_H
#include <string>
#include <iostream>


class ClapTrap
{
private:
	std::string name;
	int hitPoint;
	int energyPoint;
	int attackDamage;
public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &toCopy);
	ClapTrap& operator=(const ClapTrap &tocopy);
	~ClapTrap();
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif
