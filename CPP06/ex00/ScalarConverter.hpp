#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <limits>

class CharNotPrintable : public std::exception
{
public:
	const char *what() const throw()
	{
		return "Char not displayable";
	}
};

class ScalarConverter
{
public:
	static void convert(const std::string &var);
	ScalarConverter();
	ScalarConverter(ScalarConverter const &obj);
	~ScalarConverter(void);
	ScalarConverter		&operator=(ScalarConverter const &obj);
private:
	static void convertChar(char c);
	static void convertInt(int intValue);
	static void convertFloat(float floatValue);
	static void convertDouble(double doubleValue);
};

#endif
