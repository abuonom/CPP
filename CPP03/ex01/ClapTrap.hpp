#include <string>
#include <iostream>


class ClapTrap
{
protected:
	std::string name;
	int hitPoint;
	int energyPoint;
	int attackDamage;
public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &toCopy);
	ClapTrap& operator=(const ClapTrap &tocopy);
	~ClapTrap();
	virtual void		attack(const std::string& target);
	void				takeDamage(unsigned int amount);
	void				beRepaired(unsigned int amount);
	std::string	getName();
};
