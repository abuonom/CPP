#include "Point.hpp"
#include <iostream>

bool ft_sameSign(float num1, float num2, float num3)
{
	return (num1 >= 0.0f) == (num2 >= 0.0f) && (num2 >= 0.0f) == (num3 >= 0.0f);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	if(a == point || b == point || c == point)
		return (false);
	Point AB(b.getX().toFloat() - a.getX().toFloat(), b.getY().toFloat() - a.getY().toFloat());
	Point BC(c.getX().toFloat() - b.getX().toFloat(), c.getY().toFloat() - b.getY().toFloat());
	Point CA(a.getX().toFloat() - c.getX().toFloat(), a.getY().toFloat() - c.getY().toFloat());
	Point AP(point.getX().toFloat() - a.getX().toFloat(), point.getY().toFloat() - a.getY().toFloat());
	Point BP(point.getX().toFloat() - b.getX().toFloat(), point.getY().toFloat() - b.getY().toFloat());
	Point CP(point.getX().toFloat() - c.getX().toFloat(), point.getY().toFloat() - c.getY().toFloat());
	float ABAP = AB.getX().toFloat() * AP.getY().toFloat() - AB.getY().toFloat() * AP.getX().toFloat();
	float BCBP = BC.getX().toFloat() * BP.getY().toFloat() - BC.getY().toFloat() * BP.getX().toFloat();
	float CACP = CA.getX().toFloat() * CP.getY().toFloat() - CA.getY().toFloat() * CP.getX().toFloat();
	if(ABAP == 0 || BCBP == 0 || CACP == 0)
		return (false);
	return ft_sameSign(ABAP,BCBP,CACP);
}

/*
•a, b, c: The vertices triangle.
•point: The point to check.
•Returns:
True if the point is inside the triangle.
False otherwise or if the point is a vertex or on edge, it will return False.
*/
