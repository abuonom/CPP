#include <iostream>
#include <fstream>
#include <string>
#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl = Harl();
	if(argc != 2)
	{
		std::cout<<"INPUT: <filename> <str>";
		return (1);
	}
	std::string input = argv[1];
	harl.complain(input);
}



