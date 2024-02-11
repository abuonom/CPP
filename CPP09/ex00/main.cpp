#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr<< "INPUT FILE REQUIRED" <<std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange BtEx(argv[1]);
		BtEx.loadExchangeData();
		//BtEx.printExchangeData();
		BtEx.PrintResult();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}
