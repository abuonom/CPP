#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>
#include <sstream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->numberSaved = 0;
	this->oldest = 0;
}

void PhoneBook::addNewContact()
{
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

	while(firstName.empty() && std::cin != false)
	{
		std::cout<<"Insert Fist Name:\n";
		std::cin>>firstName;
	}
	while(lastName.empty() && std::cin != false)
	{
		std::cout<<"Insert Last Name:\n";
		std::cin>>lastName;
	}
	while(nickName.empty() && std::cin != false)
	{
		std::cout<<"Insert Nick Name:\n";
		std::cin>>nickName;
	}
	while(phoneNumber.empty() && std::cin != false)
	{
		std::cout<<"Insert Phone Number:\n";
		std::cin>>phoneNumber;
	}
	while(darkestSecret.empty() && std::cin != false)
	{
		std::cout<<"Insert darkest secret:\n";
		std::cin>>darkestSecret;
	}
	Contact contact = Contact(firstName,lastName,nickName,phoneNumber,darkestSecret);
	if(this->numberSaved != 8)
	{
		this->contacts[this->numberSaved] = contact;
		this->numberSaved++;
	}
	else
	{
		this->contacts[this->oldest] = contact;
		if(this->oldest + 1 == 8)
			this->oldest = 0;
		else
			this->oldest++;
	}
}

void PhoneBook::searchContact()
{
	int index;
	if(this->numberSaved == 0)
		std::cout<<"I'm the only one there, there is not contacts!!!\n";
	else
	{
		for(int i = 0; i < this->numberSaved; i++)
		{
			std::cout<<"         "<<i + 1;
			std::cout<<"|";
			printManipulate(this->contacts[i].getFirstName());
			std::cout<<"|";
			printManipulate(this->contacts[i].getLastName());
			std::cout<<"|";
			printManipulate(this->contacts[i].getNickName());
			std::cout<<"|\n";
		}
		std::cout<<"Insert index:\n";
		std::cin>>index;
		if(std::cin == false)
			return ;
		if(index > this->numberSaved || index <= 0)
			std::cout<<"Inserire un indice corretto\n";
		else
		{
			index--;
			std::cout<<"-"<<this->contacts[index].getFirstName()<<std::endl;
			std::cout<<"-"<<this->contacts[index].getLastName()<<std::endl;
			std::cout<<"-"<<this->contacts[index].getNickName()<<std::endl;
			std::cout<<"-"<<this->contacts[index].getPhoneNumber()<<std::endl;
			std::cout<<"-"<<this->contacts[index].getDarkestSecret()<<std::endl;
		}
	}
}

void PhoneBook::printManipulate(std::string text)
{
	if(text.length() > 10)
	{
		std::cout << std::right << std::setw(10) << text.substr(0, 10 - 1) + ".";
	}
	else
		std::cout << std::right << std::setw(10) << text;
}
