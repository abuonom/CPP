#include "Point.hpp"

	Point::Point() : x(Fixed(0)),y(Fixed(0))
	{

	}

	Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y))
	{

	} //double float

	Point::Point(const Point &other) : x(Fixed(other.getX().toFloat())), y(Fixed(other.getY().toFloat()))
	{
		*this = other;
		return;
	} //copia

	bool Point::operator==(const Point &other) const
	{
		if(this->x.getRawBits() == other.x.getRawBits() && this->y.getRawBits() == other.y.getRawBits())
			return true;
		return false;
	}

	Point &Point::operator=(const Point &other)
	{
		if (this != &other)
		{

		}
		return *this;
	}

	Point::~Point()
	{

	}

	const Fixed Point::getX() const
	{
		return (this->x);
	}

	const Fixed Point::getY() const
	{
		return (this->y);
	}


