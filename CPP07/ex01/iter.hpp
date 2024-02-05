
#ifndef ITER_HPP
# define ITER_HPP
#include <cstddef>


template <typename T, typename A>

void iter(T *array, size_t lenght, void (*func)(A))
{
	for(size_t i = 0; i < lenght; i++)
	{
		func(array[i]);
	}
}
#endif
