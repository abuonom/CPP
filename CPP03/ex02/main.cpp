#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	// Creazione di un oggetto ClapTrap chiamato "Clap1"
	ClapTrap Clap1("Claudio");

	// Copia di Clap1 utilizzando il costruttore di copia
	ClapTrap Clap2 = Clap1;

	std::cout << "\n";

	// Creazione di un oggetto ScavTrap chiamato "Scav1"
	ScavTrap Scav1("Pasquale");

	// Copia di Scav1 utilizzando il costruttore di copia
	ScavTrap Scav2 = Scav1;

	std::cout << "\n";

	// Creazione di un oggetto FragTrap chiamato "Frag1"
	FragTrap Frag1("Francesco");

	// Copia di Frag1 utilizzando il costruttore di copia
	FragTrap Frag2 = Frag1;

	std::cout << "\n";

	// Chiamata a metodi su Clap1
	Clap1.attack("Enemy1");
	Clap1.takeDamage(3);
	Clap1.beRepaired(2);

	std::cout << "\n";

	// Chiamata a metodi su Clap2
	Clap2.attack("Enemy2");
	Clap2.takeDamage(5);
	Clap2.beRepaired(3);

	std::cout << "\n";

	// Chiamata a metodi su Scav1
	Scav1.attack("Enemy3");
	Scav1.takeDamage(4);
	Scav1.beRepaired(1);
	Scav1.guardGate();

	std::cout << "\n";

	// Chiamata a metodi su Scav2
	Scav2.attack("Enemy4");
	Scav2.takeDamage(2);
	Scav2.beRepaired(4);
	Scav2.guardGate();

	std::cout << "\n";

	// Chiamata a metodi su Frag1
	Frag1.attack("Enemy5");
	Frag1.takeDamage(7);
	Frag1.beRepaired(5);
	Frag1.highFivesGuys();

	std::cout << "\n";

	// Chiamata a metodi su Frag2
	Frag2.attack("Enemy6");
	Frag2.takeDamage(2);
	Frag2.beRepaired(4);
	Frag2.highFivesGuys();

	return 0;
}
