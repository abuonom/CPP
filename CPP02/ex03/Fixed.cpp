#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed()
{
	this->fixedValue = 0;
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
	return;
}

Fixed::Fixed(const int value)
{
	this->fixedValue = value << this->fractionalBits;
}

Fixed::Fixed(const float value)
{
	this->fixedValue = roundf(value * (1 << this->fractionalBits));
}


Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		fixedValue = other.fixedValue;
	return *this;
}

Fixed::~Fixed()
{
}


int Fixed::getRawBits( void ) const
{
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

Fixed &Fixed::operator++()
{
	fixedValue += 1 << fractionalBits;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++(this->fixedValue);
	return (temp);
}

Fixed &Fixed::operator--()
{
	fixedValue -= 1 << fractionalBits;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--(this->fixedValue);
	return (temp);
}

Fixed Fixed::operator+(const Fixed &other)
{
	// Creazione di un oggetto Fixed per contenere il risultato della somma
	Fixed result;

	// Somma dei valori grezzi (raw bits) dell'istanza corrente e dell'oggetto passato come parametro
	int sum = this->getRawBits() + other.getRawBits();

	// Impostazione del valore grezzo (raw bits) del risultato
	result.setRawBits(sum);

	// Restituzione del risultato
	return result;
}

Fixed Fixed::operator-(const Fixed &other)
{
	Fixed result;
	int sum = this->getRawBits() - other.getRawBits();
	result.setRawBits(sum);
	return result;
}

Fixed Fixed::operator*(const Fixed &other)
{
	Fixed result;

	// Moltiplica i valori grezzi (raw bits) dei due oggetti Fixed
	long long multiplication = static_cast<long long>(this->getRawBits()) * other.getRawBits();

	// Shifta a destra il risultato per mantenere la rappresentazione a punto fisso corretta
	multiplication >>= fractionalBits;

	// Imposta il valore grezzo (raw bits) del risultato
	result.setRawBits(static_cast<int>(multiplication));

	return result;
}

Fixed Fixed::operator/(const Fixed &other)
{
	Fixed result;

	// Esegue uno shift a sinistra del valore grezzo dell'istanza corrente
	// Prima della divisione per mantenere la rappresentazione corretta a punto fisso
	long long division = (static_cast<long long>(this->getRawBits()) << fractionalBits) / other.getRawBits();

	// Imposta il valore grezzo (raw bits) del risultato
	result.setRawBits(static_cast<int>(division));

	return result;
}

const Fixed &Fixed::min(const Fixed &fixedOne,const Fixed &fixedTwo)
{
	return(fixedOne.getRawBits() < fixedTwo.getRawBits() ? fixedOne : fixedTwo);
}

Fixed &Fixed::min(Fixed &fixedOne, Fixed &fixedTwo)
{
	return(fixedOne.getRawBits() < fixedTwo.getRawBits() ? fixedOne : fixedTwo);
}

const Fixed &Fixed::max(const Fixed &fixedOne,const Fixed &fixedTwo)
{
	return(fixedOne.getRawBits() > fixedTwo.getRawBits() ? fixedOne : fixedTwo);
}

Fixed &Fixed::max(Fixed &fixedOne, Fixed &fixedTwo)
{
	return(fixedOne.getRawBits() > fixedTwo.getRawBits() ? fixedOne : fixedTwo);
}

std::ostream& operator<<(std::ostream& output, const Fixed& c)
{
	output<<c.toFloat();
	return output;
}


