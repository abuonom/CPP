#include "Array.hpp"
#include <iostream>
#include <stdlib.h>
#define MAX_VAL 750

int main()
{
	std::cout << "Array di interi:" << std::endl;
	Array<int> intArray(5);
	for (size_t i = 0; i < intArray.size(); ++i)
	{
		intArray[i] = i * 10;
	}
	for (size_t i = 0; i < intArray.size(); ++i)
	{
		std::cout << "Elemento " << i << ": " << intArray[i] << std::endl;
	}

	std::cout << "Array con costruttore copia:" << std::endl;
	Array<int> copiedArray(intArray);
	copiedArray[2] = 100;

	std::cout << "Array originale:" << std::endl;
	for (size_t i = 0; i < intArray.size(); ++i)
	{
		std::cout << "Elemento " << i << ": " << intArray[i] << std::endl;
	}
	std::cout << "Array copiato:" << std::endl;
	for (size_t i = 0; i < copiedArray.size(); ++i)
	{
		std::cout << "Elemento " << i << ": " << copiedArray[i] << std::endl;
	}

	std::cout << "Prova eccezione:" << std::endl;
	try
	{
		int value = intArray[10];
		std::cout << "Value : " << value << std::endl;
	}
	catch (const Array<int>::IndexOut &e)
	{
		std::cerr << "Eccezione: " << e.what() << std::endl;
	}

	std::cout << "Array di costanti:" << std::endl;
	const Array<int> constArray(3);
	for (size_t i = 0; i < constArray.size(); ++i)
	{
		std::cout << "Elemento " << i << ": " << constArray[i] << std::endl;
	}

	std::cout << "Array vuoto:" << std::endl;
	Array<int> emptyArray;
	std::cout << "Dimensione dell'array vuoto: " << emptyArray.size() << std::endl;

	std::cout << "Main della evaluation" << std::endl;

	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	// SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
		std::cout << "Copia dell'array eseguita correttamente" << std::endl;
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}

	try
	{
		numbers[-2] = 0;
	}
	catch (const std::exception &e)
	{
		std::cout << "Operazione con indice negativo gestita correttamente: " << std::endl;
		std::cerr << e.what() << '\n';
	}

	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e)
	{
		std::cout << "Operazione con indice fuori limite gestita correttamente: " << std::endl;
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}

	delete[] mirror;

	std::cout << "Tutto è andato a buon fine!" << std::endl;

	return 0;
}
