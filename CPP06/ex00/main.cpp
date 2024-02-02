#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	(void) argc;
	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}
