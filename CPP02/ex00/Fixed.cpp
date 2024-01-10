#include <iostream>
#include <string>
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

Fixed&	Fixed::operator=(const Fixed &toCopy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &toCopy)
		this->setRawBits(toCopy.getRawBits());
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fpn);
}

void	Fixed::setRawBits( int const raw )
{
	this->fpn = raw;
}
