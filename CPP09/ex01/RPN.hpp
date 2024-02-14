#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib> // for atoi
#include <cstring>

class rpnException : public std::exception
{
public:
	const char *what() const throw()
	{
		return "Error: bad input";
	}
};
class InfException : public std::exception
{
public:
	const char *what() const throw()
	{
		return "∞";
	}
};

class RPN
{
private:
	std::stack<int> num;

public:
	RPN();
	~RPN();
	RPN(const RPN &toCopy);
	RPN &operator=(const RPN &toCopy);
};

#endif