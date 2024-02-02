#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP
#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

class Identify
{
private:
public:
	Identify();
	Identify(const Identify &toCopy);
	Identify &operator=(Identify const &toCopy);
	~Identify();
	static Base *generate(void);
	static void identify(Base *p);
	static void identify(Base &p);
};

/*
Utilizzo di dynamic_cast con un puntatore: dynamic_cast viene utilizzato per convertire un puntatore
polimorfico a un tipo di classe derivato in modo sicuro durante il tempo di esecuzione.
Questo può essere utile quando si desidera accedere ai membri specifici delle classi derivate
tramite un puntatore alla classe di base.

Utilizzo di dynamic_cast con un riferimento: dynamic_cast può anche essere utilizzato con un riferimento
polimorfico per eseguire una conversione di tipo sicura durante il tempo di esecuzione.
Quando si utilizza un riferimento, non si ha la possibilità di ottenere un puntatore nullo come risultato
in caso di fallimento della conversione.

Gestione di un dynamic_cast fallito: Quando dynamic_cast non può eseguire la conversione perché l'oggetto
non è del tipo richiesto o non è polimorfico, restituisce un puntatore nullo quando si utilizza un puntatore
e solleva un'eccezione std::bad_cast quando si utilizza un riferimento.

Considerazioni sulla gerarchia delle classi: Se si ha una gerarchia di classi e si utilizza dynamic_cast per
convertire un puntatore o un riferimento a una classe di base in una classe derivata, è importante assicurarsi
che la classe di base abbia almeno una funzione virtuale per consentire il casting dinamico in modo sicuro.
*/

#endif
