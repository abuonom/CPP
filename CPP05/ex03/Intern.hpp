#ifndef INTERN_HPP
#define INTERN_HPP

#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
	int checkForm(std::string form);

public:
	Intern(/* args */);
	~Intern();
	Intern(const Intern &toCopy);
	Intern &operator=(const Intern &toCopy);
	AForm *createForm(std::string form, std::string target);
	class FormNotException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "Non esiste il form inserito\n";
		}
	};
};

int Intern::checkForm(std::string form)
{
	std::string name[4] = {"presidential", "robotomy", "shrubbery"};
	int i;
	for (i = 0; i < 3; i++)
	{
		if (!name[i].find(form))
			break;
	}
	return i;
}

Intern::Intern()
{
	std::cout << "Intern created with default constructor" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destroyed" << std::endl;
}

Intern::Intern(const Intern &toCopy)
{
	*this = toCopy;
	std::cout << "Intern created with copy constructor" << std::endl;
}

Intern &Intern::operator=(const Intern &toCopy)
{
	if (this != &toCopy)
	{
		*this = toCopy;
	}
	return *this;
}

AForm *Intern::createForm(std::string form, std::string target)
{
	AForm *f;
	int i = checkForm(form);
	try
	{
		switch (i)
		{
		case 0:
			f = new PresidentialPardonForm(target);
			break;
		case 1:
			f = new RobotomyRequestForm(target);
			break;
		case 2:
			f = new ShrubberyCreationForm(target);
			break;
		default:
			throw Intern::FormNotException();
			break;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout<<"Intern creates "<<*f<<std::endl;
	return f;
}
#endif
