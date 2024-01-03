#include "Zombie.hpp"

int	main()
{
	Zombie* zombie = newZombie("fool");
	zombie->announce();
	randomChump("alberto");
	delete(zombie);
}
