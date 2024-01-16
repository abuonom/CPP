#include "ScavTrap.hpp"

int main()
{
	// Creazione di un oggetto ClapTrap chiamato "Clap1"
	ClapTrap Clap1("Claudio");

	// Copia di Clap1 utilizzando il costruttore di copia
	ClapTrap Clap2 = Clap1;

	// Creazione di un oggetto ScavTrap chiamato "Scav1"
	ScavTrap Scav1("Pasquale");

	// Copia di Scav1 utilizzando il costruttore di copia
	ScavTrap Scav2 = Scav1;

	// Chiamata a metodi su Clap1
	Clap1.attack("Enemy1");
	Clap1.takeDamage(3);
	Clap1.beRepaired(2);

	// Chiamata a metodi su Clap2
	Clap2.attack("Enemy2");
	Clap2.takeDamage(5);
	Clap2.beRepaired(3);

	// Chiamata a metodi su Scav1
	Scav1.attack("Enemy3");
	Scav1.takeDamage(4);
	Scav1.beRepaired(1);
	Scav1.guardGate();

	// Chiamata a metodi su Scav2
	Scav2.attack("Enemy4");
	Scav2.takeDamage(2);
	Scav2.beRepaired(4);
	Scav2.guardGate();

	return 0;
}
