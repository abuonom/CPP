#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	// Creazione di un bureaucrat e di alcuni form
	Bureaucrat bureaucrat("John", 50);
	Bureaucrat bureaucrat2("Anna", 150);

	// Creazione dell'oggetto Intern
	Intern intern;

	// Test di creazione dei form tramite l'oggetto Intern
	try
	{
		AForm *form1 = intern.createForm("presidential", "home");
		AForm *form2 = intern.createForm("robotomy", "target");
		AForm *form3 = intern.createForm("shrubbery", "garden");
		AForm *form4 = intern.createForm("invalidForm", "invalidTarget");

		// Utilizzare le variabili per evitare il warning di variabile non utilizzata
		if (form1)
		{
		}
		if (form2)
		{
		}
		if (form3)
		{
		}
		if (form4)
		{
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// Creazione dei form manualmente
	ShrubberyCreationForm shrubberyForm("home");
	RobotomyRequestForm robotomyForm("target");
	PresidentialPardonForm pardonForm("target");

	// Test di firma e esecuzione dei form
	try
	{
		bureaucrat.signForm(shrubberyForm);
		bureaucrat.signForm(robotomyForm);
		bureaucrat.signForm(pardonForm);
		bureaucrat.executeForm(shrubberyForm);
		bureaucrat.executeForm(robotomyForm);
		bureaucrat.executeForm(pardonForm);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
