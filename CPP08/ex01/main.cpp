#include "Span.hpp"
#include <iostream>
#include <ctime>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try
	{
		Span span(10000);
		Span spanNumbers(20);
		int array[20];
		for (int i = 0; i < 20; i++)
		{
			array[i] = rand() % 20;
		}
		spanNumbers.addNumberRange(array, array + 20);
		std::cout << "Shortest span: " << spanNumbers.shortestSpan() << std::endl;
		std::cout << "Longest span: " << spanNumbers.longestSpan() << std::endl;
		srand(static_cast<unsigned int>(time(NULL)));

		// Aggiungi 10.000 numeri casuali alla Span
		for (int i = 0; i < 10000; ++i)
		{
			span.addNumber(rand());
		}

		// Calcola e stampa il minimo e il massimo intervallo
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
