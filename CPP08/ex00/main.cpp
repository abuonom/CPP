#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"

int main(void)
{
	std::cout << "VECTOR" << std::endl;
	std::vector<int> vect;

	for (int i = 0; i < 5; i++)
		vect.push_back(i);
	try
	{
		std::vector<int>::iterator iter1 = easyfind<std::vector<int> >(vect, 3);
		std::cout << "Iteratore per 3 trovato nel vettore"<<std::endl;
		iter1 = easyfind<std::vector<int> >(vect, 7);
		std::cout << "Iteratore per 7 trovato nel vettore"<<std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "DECK" << std::endl;
	std::deque<int> deck(vect.begin(), vect.end());

	try
	{
		std::deque<int>::iterator iter2 = easyfind<std::deque<int> >(deck, 3);
		std::cout << "Iteratore per 3 trovato nel deck"<<std::endl;

		iter2 = easyfind<std::deque<int> >(deck, 7);
		std::cout << "Iteratore per 7 trovato nel deck"<<std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() <<std::endl;
	}

	std::cout << "LIST" << std::endl;
	std::list<int> list(vect.begin(), vect.end());

	try
	{
		std::list<int>::iterator iter3 = easyfind<std::list<int> >(list, 3);
		std::cout << "Iteratore per 3 trovato nella lista"<<std::endl;

		iter3 = easyfind<std::list<int> >(list, 7);
		std::cout << "Iteratore per 7 trovato nella lista"<<std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
