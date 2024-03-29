#include "Harl.hpp"

Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::def(void)
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*funzArray[5])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::def};
	std::string levels[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "DEFAULT"};
	int i;
	for (i = 0; i < 4; i++)
	{
		if (!levels[i].find(level))
			break;
	}
	switch (i)
	{
	case 0:
		for (int x = 0; x < 4; x++)
			(this->*funzArray[x])();
		break;
	case 1:
		for (int x = 1; x < 4; x++)
			(this->*funzArray[x])();
		break;
	case 2:
		for (int x = 2; x < 4; x++)
			(this->*funzArray[x])();
		break;
	case 3:
		(this->*funzArray[3])();
		break;
	default:
		(this->*funzArray[4])();
	}
}
