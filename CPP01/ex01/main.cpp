#include "Zombie.hpp"

int	main()
{
	int N = 10;
	Zombie *horde = zombieHorde(N,"Steve");
	for(int i = 0; i < N; i++)
	{
		std::cout<<"Zombie["<<i<<"]";
		horde[i].announce();
		std::cout<<"\n";
	}
	delete [] horde;
}
