#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
# include "Materia.hpp"
# include "Character.hpp"

class IMateriaSource
{
public:
virtual ~IMateriaSource() {}
virtual void learnMateria(AMateria*) = 0;
virtual AMateria* createMateria(std::string const & type) = 0;
};


class MateriaSource : public IMateriaSource
{
private:
	AMateria *inventory[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &toCopy);
	MateriaSource &operator=(const MateriaSource &tocopy);
	~MateriaSource();
	void learnMateria(AMateria *);
	AMateria *createMateria(std::string const &type);
};


#endif
