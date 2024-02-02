#include "Identify.hpp"

Identify::Identify()
{
}

Identify::~Identify()
{
}

Base *Identify::generate()
{
	std::srand(std::time(0));
	int randomNumber = std::rand() % 3 + 1;
	switch (randomNumber)
	{
	case 1:
		return new A();
	case 2:
		return new B();
	case 3:
		return new C();
	default:
		return 0;
	}
}

void Identify::identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "Class A" << std::endl;
	if (dynamic_cast<B *>(p) != NULL)
		std::cout << "Class B" << std::endl;
	if (dynamic_cast<C *>(p) != NULL)
		std::cout << "Class C" << std::endl;
}
void Identify::identify(Base &p)
{
	try
	{
		dynamic_cast<A&>(p);
	}
	catch(const std::exception& e)
	{
		try
		{
			dynamic_cast<B&>(p);
		}
		catch(const std::exception& e)
		{
			dynamic_cast<C&>(p);
		}

	}

}
