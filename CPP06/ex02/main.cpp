#include "Identify.hpp"

int main()
{
	Base *ptr = Identify::generate();
	Identify::identify(ptr);
	Base &ref = *ptr;
	Identify::identify(ref);
	delete ptr;

	Base *a = new A();
	Identify::identify(a);
	Base *b = new B();
	Identify::identify(b);
	Base *c = new C();
	Identify::identify(c);

	delete a;
	delete b;
	delete c;
	return 0;
}
