#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <cstddef>
#include <exception>

template <typename T>
class Array
{
private:
	T *vector;
	size_t _size;

public:
	Array();
	Array(unsigned int size);
	Array(const Array &toCopy);
	Array &operator=(Array const &toCopy);
	T &operator[](int index);
	const T &operator[](int index) const;
	~Array();
	size_t size() const;
	class IndexOut : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "Index out of bounds";
		}
	};
};

template <typename T>
Array<T>::Array()
{
	vector = NULL;
	_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int size)
{
	this->_size = size;
	vector = new T[_size];
	for (size_t i = 0; i < this->_size; i++)
		vector[i] = 0;
}

template <typename T>
Array<T>::Array(const Array &toCopy)
{
	this->_size = toCopy._size;
	this->vector = new T[_size];
	for (size_t i = 0; i < _size; i++)
		vector[i] = toCopy.vector[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &toCopy)
{
	if (this != &toCopy)
	{
		delete[] vector;
		_size = toCopy._size;
		this->vector = new T[_size];
		for (size_t i = 0; i < _size; i++)
		{
			vector[i] = toCopy.vector[i];
		}
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](int index)
{
	if (index >= (int)_size || index < 0)
		throw Array::IndexOut();
	return (vector[index]);
}

template <typename T>
T const &Array<T>::operator[](int index) const
{
	if (index >= (int)_size || index < 0)
		throw Array::IndexOut();
	return (vector[index]);
}

template <typename T>
Array<T>::~Array()
{
	delete[] vector;
}

template <typename T>
size_t Array<T>::size() const
{
	return this->_size;
}
#endif
