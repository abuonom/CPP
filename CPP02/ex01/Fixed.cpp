#include <iostream>
#include <string>
#include <cmath>
#include "Fixed.hpp"

const int Fixed::fractBits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fpn = 0;
}

Fixed::Fixed(const Fixed &toCopy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = toCopy;
	return;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->fpn = num << this->fractBits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->fpn = roundf(num * (1 << this->fractBits));
}

Fixed&	Fixed::operator=(const Fixed &toCopy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &toCopy)
		this->setRawBits(toCopy.getRawBits());
	return *this;
}

std::ostream&	operator<<(std::ostream& outStream, const Fixed& obj)
{
	outStream << obj.toFloat();
	return outStream;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const
{
	return (this->fpn);
}

void	Fixed::setRawBits( int const raw )
{
	this->fpn = raw;
}

float	Fixed::toFloat( void ) const
{
	return float(this->fpn) / (1 << this->fractBits);
}

int	Fixed::toInt( void ) const
{
	return this->fpn / (1 << this->fractBits);
}
