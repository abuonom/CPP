#include "main.h"

int main()
{
	std::string input;
	PhoneBook phonebook = PhoneBook();

	std::cout<<"Welcome to the PhoneBook\n";
	while(input.compare("EXIT") && std::cin != false)
	{
		std::cout<<"Insert ADD / SEARCH / EXIT\n";
		std::cin.clear();
		std::cin >> input;
		if(!input.compare("ADD"))
		{
			phonebook.addNewContact();
		}
		else if(!input.compare("SEARCH"))
		{
			phonebook.searchContact();
		}
	}
}
