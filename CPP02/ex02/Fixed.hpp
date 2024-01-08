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
	Fixed	&operator=(const Fixed &other); // overload dell'operatore copia, mi permette di copiare un oggetto in un altro
};
#endif
std::ostream& operator<<(std::ostream& output, const Fixed& c);

/*
•The 4 arithmetic operators: +, -, *, and /.
•The 4 increment/decrement (pre-increment and post-increment, pre-decrement and
post-decrement) operators, that will increase or decrease the fixed-point value from
the smallest representable ε such as 1 + ε > 1.
Add these four public overloaded member functions to your class:
•A static member function min that takes as parameters two references on fixed-point
numbers, and returns a reference to the smallest one.
•A static member function min that takes as parameters two references to constant
fixed-point numbers, and returns a reference to the smallest one.
•A static member function max that takes as parameters two references on fixed-point
numbers, and returns a reference to the greatest one.
•A static member function max that takes as parameters two references to constant
fixed-point numbers, and returns a reference to the greatest one.
10



*/

