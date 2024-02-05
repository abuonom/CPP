#include "Array.hpp"
#include <iostream>

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

	return 0;
}
