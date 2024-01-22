#ifndef CHARACTER_HPP
#define CHARACTER_HPP
# include <string>
# include <iostream>
# include "Materia.hpp"


class ICharacter
{
public:
	virtual ~ICharacter() {}
	virtual std::string const &getName() const = 0;
	virtual void equip(AMateria *m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter &target) = 0;
};

class Character : public ICharacter
{
private:
	AMateria *inventory[4];
	AMateria *floor[200];
	std::string name;

public:
	Character(std::string name);
	Character(const Character &toCopy);
	Character &operator=(const Character &toCopy);
	~Character();
	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
	void cleanFloor();
};
#endif
