#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib> // for atoi
#include <cstring>
#include <exception>
#include <ctime>

class rpnException : public std::exception
{
public:
	const char *what() const throw()
	{
		return "Error: bad input";
	}
};
class ZeroException : public std::exception
{
public:
	const char *what() const throw()
	{
		return "N/0 is impossible for me :(";
	}
};

class RPN
{
private:
	std::stack<int> num;
	std::string expression;
public:
	RPN(std::string expression);
	~RPN();
	RPN(const RPN &toCopy);
	RPN &operator=(const RPN &toCopy);
	int operation();
	clock_t start_t = clock();
};

#endif
