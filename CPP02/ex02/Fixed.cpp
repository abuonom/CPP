#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed()
{
	this->fixedValue = 0;
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout<<"Copy constructor called"<<std::endl;
	*this = other;
	return;
}

Fixed::Fixed(const int value)
{
	std::cout<<"Integer constructor called"<<std::endl;
	this->fixedValue = value << this->fractionalBits;
}

Fixed::Fixed(const float value)
{
	this->fixedValue = roundf(value * (1 << this->fractionalBits));
	std::cout<<"Float constructor called"<<std::endl;
}


Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	if (this != &other)
		fixedValue = other.fixedValue;
	return *this;
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}


int Fixed::getRawBits( void ) const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return (this->fixedValue);
}

void Fixed::setRawBits( int const raw )
{
	this->fixedValue = raw;
}

float Fixed::toFloat( void ) const
{
	return float(this->fixedValue) / (1 << this->fractionalBits);
}

int Fixed::toInt( void ) const
{
	return this->fixedValue / (1 << this->fractionalBits);
}

bool Fixed::operator>(const Fixed &other)
{
	if(this->fixedValue > other.fixedValue)
		return true;
	return false;
}

bool Fixed::operator<(const Fixed &other)
{
	if(this->fixedValue < other.fixedValue)
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &other)
{
	if(this->fixedValue >= other.fixedValue)
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed &other)
{
	if(this->fixedValue <= other.fixedValue)
		return true;
	return false;
}

bool Fixed::operator==(const Fixed &other)
{
	if(this->fixedValue == other.fixedValue)
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed &other)
{
	if(this->fixedValue != other.fixedValue)
		return true;
	return false;
}

std::ostream& operator<<(std::ostream& output, const Fixed& c)
{
	output<<c.toFloat();
	return output;
}


