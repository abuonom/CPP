#include "Contact.hpp"

class PhoneBook
{
	private:
	Contact contacts[8];
	int	numberSaved;
	int	oldest;

	public:
	PhoneBook();
	void addNewContact();
	void searchContact();
	void printManipulate(std::string text);
};
