#include "DiamondTrap.hpp"

using std::cout;

int main()
{
	// Creazione di un oggetto DiamondTrap chiamato "Diamond1"
	DiamondTrap Diamond1("Davide");

	cout << "\n";

	// Copia di Diamond1 utilizzando il costruttore di copia
	DiamondTrap Diamond2 = Diamond1;

	cout << "\n";

	// Chiamata a metodi su Diamond1
	Diamond1.whoAmI(); // Chiama il metodo specifico di DiamondTrap
	Diamond1.attack("Enemy1");
	Diamond1.takeDamage(3);
	Diamond1.beRepaired(2);

	cout << "\n";

	// Chiamata a metodi su Diamond2
	Diamond2.whoAmI(); // Chiama il metodo specifico di DiamondTrap
	Diamond2.attack("Enemy2");
	Diamond2.takeDamage(5);
	Diamond2.beRepaired(3);

	cout << "\n";

	return 0;
}
