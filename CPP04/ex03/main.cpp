#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Materia.hpp"

int main()
{
	std::cout << "STARTING PROGRAM...\n" << std::endl;

	std::cout << "CREATING MATERIASOURCE...\n" << std::endl;
	IMateriaSource *src = new MateriaSource();
	std::cout << "\nUSING LEARNMATERIA...\n" << std::endl;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << "\nCREATING CHARACTER\n" << std::endl;
	ICharacter *me = new Character("me");

	std::cout << "CREATING TMP MATERIA\n" << std::endl;
	AMateria *tmp;
	tmp = src->createMateria("ice");
	std::cout << "TRY EQUIP TMP ICE MATERIA\n" << std::endl;
	me->equip(tmp);
	std::cout << "TRY EQUIP TMP CURE MATERIA\n" << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "CREATING NEW CHARACTER\n" << std::endl;
	ICharacter *bob = new Character("bob");

	std::cout << "TRY UNEQUIP MATERIA IDX 0 \n" << std::endl;
	me->unequip(0);
	bob->unequip(0);

	std::cout << "USING MATERIA AT INDEX 0..." << std::endl;
	me->use(0, *bob);

	std::cout << "USING MATERIA AT INDEX 1..." << std::endl;
	me->use(1, *bob);

	std::cout << "CLEANING UP..." << std::endl;
	delete bob;
	delete me;
	delete src;

	std::cout << "PROGRAM FINISHED." << std::endl;

	return 0;
}
