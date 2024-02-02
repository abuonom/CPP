#include "Data.hpp"

Data::Data(int data) : data(data)
{
}

Data::~Data()
{
}

Data::Data(Data const &toCopy)
{
	this->data = toCopy.data;
}
Data &Data::operator=(Data const &toCopy)
{
	if (this != &toCopy)
	{
		this->data = toCopy.data;
	}
	return *this;
}

bool Data::operator==(const Data &other) const
{
	return (this->data == other.data);
}
