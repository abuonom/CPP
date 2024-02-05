#include "iter.hpp"
#include <iostream>
#include <string>

// Funzione per stampare gli elementi di un array di tipo T
template <typename T>
void stampa(T num)
{
	std::cout << num << std::endl;
}

// Struttura per gli oggetti personalizzati
struct Prodotto
{
	std::string nome;
	double prezzo;
};

// Funzione per stampare gli elementi di un array di oggetti Prodotto
void stampaProdotto(const Prodotto &prodotto)
{
	std::cout << "Nome: " << prodotto.nome << ", Prezzo: " << prodotto.prezzo << std::endl;
}

int main()
{
	// Array di interi
	int arrayInt[5] = {1, 2, 3, 4, 5};
	std::cout << "Array di interi:" << std::endl;
	iter(arrayInt, 5, stampa<int>);
	std::cout << std::endl;

	// Array di caratteri
	char arrayChar[5] = {'a', 'b', 'c', 'd', 'e'};
	std::cout << "Array di caratteri:" << std::endl;
	iter(arrayChar, 5, stampa<char>);
	std::cout << std::endl;

	// Array di oggetti Prodotto
	Prodotto arrayProdotti[3] = {{"Prodotto1", 10.99}, {"Prodotto2", 20.49}, {"Prodotto3", 15.79}};
	std::cout << "Array di oggetti Prodotto:" << std::endl;
	iter(arrayProdotti, 3, stampaProdotto);

	return 0;
}

/*

"Instantiated function template" è un termine che si riferisce a una funzione che è stata generata a partire
da un template di funzione tramite l'istanziazione con un tipo di dato specifico.
In C++, i template di funzione forniscono un meccanismo per creare funzioni generiche che possono lavorare
con diversi tipi di dati senza dover scrivere codice separato per ciascun tipo.

Quando si utilizza un template di funzione in C++, viene fornito il tipo di dato specifico con cui si desidera
 istanziare la funzione.
Questo processo di generazione di una versione concreta di una funzione da un template di funzione
è chiamato "istanziazione".

Il compilatore genera una versione specifica della funzione square per il tipo int.
Questa versione specifica è l'"instantiated function template" per il tipo int.
Il processo di creazione di questa versione specifica della funzione è chiamato "istanziazione del template di funzione".
Lo stesso template di funzione può essere istanziato con altri tipi di dati, come double, float, ecc., e generare funzioni corrispondenti per ciascun tipo di dati.

*/
