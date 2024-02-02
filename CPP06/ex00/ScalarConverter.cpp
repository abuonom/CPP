#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(ScalarConverter const &obj)
{
	*this = obj;
}
ScalarConverter::~ScalarConverter(void)
{

}
ScalarConverter		&ScalarConverter::operator=(ScalarConverter const &obj)
{
	if(this != &obj)
	{

	}
	return *this;
}

void ScalarConverter::convert(const std::string &var)
{
	if (var.empty())
	{
		throw std::invalid_argument("Input string is empty");
	}

	if (var == "nan" || var == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return;
	}

	if (var == "-inff" || var == "-inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return;
	}

	if (var == "+inff" || var == "+inf" || var == "inf" || var == "inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
		return;
	}

	char *endptr;
	if (!var.empty() && var[var.length() - 1] == 'f') // Se la stringa termina con 'f', considerala come float
	{
		float floatValue = std::strtof(var.substr(0, var.length() - 1).c_str(), &endptr);
		if (*endptr == '\0')
		{
			convertFloat(floatValue);
			return;
		}
	}

	long long longValue = std::strtoll(var.c_str(), &endptr, 10);
	if (*endptr == '\0' && longValue >= std::numeric_limits<int>::min() && longValue <= std::numeric_limits<int>::max())
	{
		convertInt(static_cast<int>(longValue));
		return;
	}

	double doubleValue = std::strtod(var.c_str(), &endptr);
	if (*endptr == '\0')
	{
		convertDouble(doubleValue);
		return;
	}

	try
	{
		convertChar(var.at(0));
	}
	catch (const std::out_of_range &)
	{
		throw std::invalid_argument("Conversion failed for input: " + var);
	}
}

void ScalarConverter::convertChar(char c)
{
	std::cout << "char : " << c << std::endl;
	std::cout << "int : " << static_cast<int>(c) << std::endl;
	std::cout << "float : " << static_cast<float>(c) << std::endl;
	std::cout << "double : " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convertInt(int intValue)
{
	std::cout << "char : ";
	if (isprint(intValue))
	{
		std::cout << static_cast<char>(intValue) << std::endl;
	}
	else
	{
		std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int : " << intValue << std::endl;
	std::cout << "float : " << static_cast<float>(intValue) << std::endl;
	std::cout << "double : " << static_cast<double>(intValue) << std::endl;
}

void ScalarConverter::convertFloat(float floatValue)
{
	std::cout << "char : ";
	if (isprint(static_cast<int>(floatValue)))
	{
		std::cout << static_cast<char>(floatValue) << std::endl;
	}
	else
	{
		std::cout << "Non displayable" << std::endl;
	}

	int roundedIntValue;
	if (floatValue - std::floor(floatValue) < 0.5f)
	{
		roundedIntValue = static_cast<int>(std::floor(floatValue)); // Arrotonda verso il basso
	}
	else
	{
		roundedIntValue = static_cast<int>(std::ceil(floatValue)); // Arrotonda verso l'alto
	}

	float roundedFloatValue = static_cast<float>(roundedIntValue); // Casting a float dopo l'arrotondamento
	std::cout << "int : " << roundedIntValue << std::endl;
	std::cout << "float : " << roundedFloatValue << "f" << std::endl;
	std::cout << "double : " << static_cast<double>(floatValue) << std::endl;
}

void ScalarConverter::convertDouble(double doubleValue)
{
	std::cout << "char : ";
	if (isprint(static_cast<int>(doubleValue)))
	{
		std::cout << static_cast<char>(doubleValue) << std::endl;
	}
	else
	{
		std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int : " << static_cast<int>(doubleValue) << std::endl;
	std::cout << "float : " << static_cast<float>(doubleValue) << std::endl;

	if (std::isinf(doubleValue))
	{
		if (doubleValue > 0)
		{
			std::cout << "double : +inf" << std::endl;
		}
		else
		{
			std::cout << "double : -inf" << std::endl;
		}
	}
	else
	{
		std::cout << "double : " << doubleValue << std::endl;
	}
}
