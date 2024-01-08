#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
private:
const Fixed x;
const Fixed y;
//Anything else useful
public:
	Point();
	Point(const float x, const float y); //double float
	Point(const Point &other); //copia
	Point	&operator=(const Point &other);
	bool	operator==(const Point &other) const; //overload operatore uguale uguale, mi permette di confrontare due oggetti e sapere se sono uguali
	~Point();
	const Fixed getX() const;
	const Fixed getY() const;
	//Anything else useful
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
#endif
