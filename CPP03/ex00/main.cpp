#include "ClapTrap.hpp"

int main() {
    // Creazione di un oggetto ClapTrap chiamato "Clap1"
    ClapTrap Clap1("CL4P-TP");

    // Copia di Clap1 utilizzando il costruttore di copia
    ClapTrap Clap2 = Clap1;

    // Copia di Clap1 utilizzando l'operatore di assegnazione
    ClapTrap Clap3("Another CL4P-TP");
    Clap3 = Clap1;

    // Chiamata a metodi su Clap1
    Clap1.attack("Enemy1");
    Clap1.takeDamage(3);
    Clap1.beRepaired(2);

    // Chiamata a metodi su Clap2
    Clap2.attack("Enemy2");
    Clap2.takeDamage(5);
    Clap2.beRepaired(3);

    // Chiamata a metodi su Clap3
    Clap3.attack("Enemy3");
    Clap3.takeDamage(4);
    Clap3.beRepaired(1);

    // Output dei distruttori
    std::cout << "Distruttore di Clap3" << std::endl;
    std::cout << "Distruttore di Clap2" << std::endl;
    std::cout << "Distruttore di Clap1" << std::endl;

    return 0;
}
