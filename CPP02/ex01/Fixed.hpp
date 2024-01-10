#ifndef Fixed_HPP
#define Fixed_HPP

#include <string>

class Fixed
{
private:
	int					fpn;
	static const int	fractBits;

public:
	Fixed();
	Fixed(const Fixed &toCopy);
	Fixed(const int num);
	Fixed(const float num);
	~Fixed();
	Fixed&	operator=(const Fixed &toCopy);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& obj);

#endif
