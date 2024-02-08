#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>
#include <cstdlib>
#include <ctime>
/*
Develop a Span class that can store a maximum of N integers. N is an unsigned int
variable and will be the only parameter passed to the constructor.
This class will have a member function called addNumber() to add a single number
to the Span. It will be used in order to fill it. Any attempt to add a new element if there
are already N elements stored should throw an exception.
Next, implement two member functions: shortestSpan() and longestSpan()
They will respectively find out the shortest span or the longest span (or distance, if
you prefer) between all the numbers stored, and return it. If there are no numbers stored,
or only one, no span can be found. Thus, throw an exception.
Of course, you will write your own tests and they will be way more thorough than the
ones below. Test your Span at least with a minimum of 10 000 numbers. More would be
even better.

Last but not least, it would be wonderful to fill your Span using a range of iterators.
Making thousands calls to addNumber() is so annoying. Implement a member function
to add many numbers to your Span in one call.

*/

class Span
{
private:
	int _size;
	std::vector<int> _vec;

public:
	Span(unsigned int N);
	Span(const Span &tocopy);
	Span &operator=(Span const &toCopy);
	~Span();
	void addNumber(int value);
	int shortestSpan();
	int longestSpan();
	int getSize() const;

	class OutOfRange : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "Out of range";
		}
	};

	class NoSpanFound : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "No span has found";
		}
	};

	template <typename T>
	void addNumberRange(T begin, T end)
	{
		for (T i = begin; i < end; i++)
		{
			this->addNumber(*i);
		}
	}
};

#endif
