#include "PmergeMe.hpp"
#include <deque>
#include <vector>
#include <iostream>
#include <ctime>

bool is_valid_input(std::string str)
{
	// Controlla se la stringa è vuota
	if (str.empty())
		return false;
	// Controlla se la stringa contiene solo cifre
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	int value = std::atoi(str.c_str());
	if (value < 0)
		return false;
	return true;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "INSERT ONE NUMBER AT LEAST" << std::endl;
		return 1;
	}

	for (int i = 1; i < argc; i++)
	{
		if (!is_valid_input(argv[i]))
		{
			std::cerr << "Bad Input" << std::endl;
			return 1;
		}
	}

	try
	{
		PmergeMe<std::deque<unsigned int> > pmergeDeque(argc, argv);
		std::cout << "Before deque: ";
		pmergeDeque.printContainer(pmergeDeque.getContainer());
		clock_t start_time = clock();
		std::cout << "Sorted deque: ";
		pmergeDeque.printContainer(pmergeDeque.mergeInsertionSort(pmergeDeque.getContainer(), 2));
		clock_t end_time = clock();
		double duration = (end_time - start_time) / static_cast<double>(CLOCKS_PER_SEC) * 1e6; // Converti da secondi a microsecondi
		std::cout << "Time to process a range of " << pmergeDeque.getContainer().size() << " elements with std::deque : " << duration << " us" << std::endl;

		PmergeMe<std::vector<unsigned int> > pmergeVector(argc, argv);
		std::cout << "Before vector: ";
		pmergeVector.printContainer(pmergeVector.getContainer());
		std::cout << "Sorted vector: ";
		pmergeVector.printContainer(pmergeVector.mergeInsertionSort(pmergeVector.getContainer(), 2));
		start_time = clock();
		end_time = clock();
		duration = (end_time - start_time) / static_cast<double>(CLOCKS_PER_SEC) * 1e6; // Converti da secondi a microsecondi
		std::cout << "Time to process a range of " << pmergeVector.getContainer().size() << " elements with std::vector : " << duration << " us" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}

	return 0;
}
