#include "main.h"

	Contact::Contact()
	{
	}
	Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
	{
		this->firstName = firstName;
		this->lastName = lastName;
		this->nickName = nickName;
		this->phoneNumber = phoneNumber;
		this->darkestSecret = darkestSecret;
	}

	std::string Contact::getFirstName()
	{
		return (this->firstName);
	}

	std::string Contact::getLastName()
	{
		return (this->lastName);
	}

	std::string Contact::getNickName()
	{
		return (this->nickName);
	}

	std::string Contact::getPhoneNumber()
	{
		return (this->phoneNumber);
	}

	std::string Contact::getDarkestSecret()
	{
		return (this->darkestSecret);
	}
