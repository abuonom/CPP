#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
private:
	int fixedValue;						 // Numero a punto fisso
	static const int fractionalBits; // Numero costante di bit frazionari
public:
	Fixed();						  // default constructor
	Fixed(const Fixed &other);			  // costruttore copia, mi permette di creare un oggetto a partire da un altro
	Fixed(const int value);				//A constructor that takes a constant integer as a parameter.
	Fixed(const float value);				//A constructor that takes a constant floating-point number as a parameter. It converts it to the corresponding fixed-point value. The fractional bits value is
	~Fixed();							  // destructor
	int		getRawBits(void) const;		// returns the raw value of the fixed-point value
	void	setRawBits(int const raw); // sets the raw value of the fixed-point number
	float	toFloat( void ) const; //converts the fixed-point value to a floating-point value.
	int		toInt( void ) const; //converts the fixed-point value to an integer value.
	bool	operator>(const Fixed &other); //overload operatore maggiore, mi permette di confrontare due oggetti e sapere se il primo è più grande del secondo
	bool	operator<(const Fixed &other); //overload operatore minore, mi permette di confrontare due oggetti e sapere se il primo è più piccolo del secondo
	bool	operator>=(const Fixed &other); //overload operatore maggiore uguale, mi permette di confrontare due oggetti e sapere se il primo è più grande o uguale al secondo
	bool	operator<=(const Fixed &other); //overload operatore minore uguale,  mi permette di confrontare due oggetti e sapere se il primo è più piccolo o uguale al secondo
	bool	operator==(const Fixed &other); //overload operatore uguale uguale, mi permette di confrontare due oggetti e sapere se sono uguali
	bool	operator!=(const Fixed &other); //overload operatore diverso, mi permette di confrontare due oggetti e sapere se sono diversi tra loro
	Fixed&	operator++(); //overload pre incremento
	Fixed	operator++(int); //overload post incremento
	Fixed&	operator--();
	Fixed	operator--(int);
	Fixed	&operator=(const Fixed &other); // overload dell'operatore copia, mi permette di copiare un oggetto in un altro
	Fixed	operator+(const Fixed &other);
	Fixed	operator-(const Fixed &other);
	Fixed	operator*(const Fixed &other);
	Fixed	operator/(const Fixed &other);
	static const Fixed &min(const Fixed &fixedOne,const Fixed &fixedTwo);
	static Fixed &min(Fixed &fixedOne, Fixed &fixedTwo);
	static const Fixed &max(const Fixed &fixedOne,const Fixed &fixedTwo);
	static Fixed &max(Fixed &fixedOne, Fixed &fixedTwo);
};
#endif
std::ostream& operator<<(std::ostream& output, const Fixed& c);

/*
•A static member function min that takes as parameters two references to constant
fixed-point numbers, and returns a reference to the smallest one.
•A static member function max that takes as parameters two references on fixed-point
numbers, and returns a reference to the greatest one.
•A static member function max that takes as parameters two references to constant
fixed-point numbers, and returns a reference to the greatest one.
10
*/

