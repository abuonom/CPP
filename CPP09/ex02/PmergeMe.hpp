#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class doubleFounded : public std::exception
{
public:
	const char *what() const throw()
	{
		return "Error: trovati duplicati nella sequenza";
	}
};

template <typename T>
class PmergeMe
{
private:
	T container;

public:
	PmergeMe(int argc, char **argv);
	~PmergeMe();
	T mergeInsertionSort(const T &data, int k);
	void printContainer(const T &data);
	const T &getContainer() const;
};

template <typename T>
const T &PmergeMe<T>::getContainer() const // getter del container utilizzato
{
	return container;
}

template <typename T>
PmergeMe<T>::PmergeMe(int argc, char **argv) // costruttore di default che inizializza il container
{
	for (int i = 1; i < argc; ++i)
	{
		container.push_back(std::atoi(argv[i]));
	}
}

template <typename T>
PmergeMe<T>::~PmergeMe() {} // distruttore

/*
Il metodo di seguito, utilizza i principi della ricorsione, per dividere il container
in porzioni sempre più piccole, fino ad arrivare a delle coppie, che ordinerà utilizzando insection-sort
e che a loro volta saranno ordinate con il merge-sort, gli viene passato come const l'array originale
per una questione di sicurezza del dato, ed un intero K che definisce la size dei sotto-array*/
template <typename T>
T PmergeMe<T>::mergeInsertionSort(const T &data, int k) // metodo principale per l'ordinamento
{
	T temp(data); // dichiaro un temporaneo, per non avere problemi con il const che mi arriva

	if (temp.size() <= static_cast<size_t>(k))		// verifico se la dimensione dell'array è minore o uguale al k scelto per il sotto-array
		std::stable_sort(temp.begin(), temp.end()); // eseguo lo stable_sort, che da reference utilizza insection_sort per ordinare i container scelti
	else
	{
		typename T::iterator mid = temp.begin() + (temp.size() / 2); // se la porzione non è una coppia, prendo il punto medio del container
		T left(temp.begin(), mid);									 // credo due porzioni di array
		T right(mid, temp.end());

		left = mergeInsertionSort(left, k); // sfrutto la ricorsione, per creare ulteriori porzioni, o risolvere il caso minimo
		right = mergeInsertionSort(right, k);

		temp.clear();																				// libero la temporanea, per metterci l'array ordinato
		std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(temp)); // utilizzo il merge-sort per unire i due sotto-array
	}
	return temp;
}

template <typename T>
void PmergeMe<T>::printContainer(const T &data)
{
	for (typename T::size_type i = 0; i < data.size(); ++i)
	{
		for (typename T::size_type j = i + 1; j < data.size(); ++j)
		{
			if (data[i] == data[j])
				throw doubleFounded();
		}
	}
	for (typename T::const_iterator it = data.begin(); it != data.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

#endif
