#include "Span.hpp"

Span::Span(unsigned int N) : _size(N)
{
}

Span::Span(const Span &tocopy)
{
	this->_size = tocopy.getSize();
}
Span &Span::operator=(Span const &toCopy)
{
	if (this != &toCopy)
		this->_size = toCopy.getSize();
	return *this;
}

Span::~Span()
{
}

int Span::getSize() const
{
	return this->_size;
}

void Span::addNumber(int value)
{
	if (_vec.size() == (long unsigned int)_size)
		throw Span::OutOfRange();
	_vec.push_back(value);
}

int Span::shortestSpan()
{
	if (_vec.size() <= 1)
		throw Span::NoSpanFound();

	std::vector<int> copy = _vec;
	std::sort(copy.begin(), copy.end());

	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < copy.size(); ++i)
	{
		int span = copy[i] - copy[i - 1];
		if (span < minSpan)
			minSpan = span;
	}

	return minSpan;
}

int Span::longestSpan()
{
	if (_vec.size() <= 1)
		throw Span::NoSpanFound();
	std::vector<int> copy = _vec;
	std::sort(copy.begin(), copy.end());
	return (copy.back() - copy.front());
}
