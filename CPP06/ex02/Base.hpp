#ifndef BASE_HPP
# define BASE_HPP

class Base
{
private:

public:
	virtual ~Base();
};


class A : public Base
{
private:

public:
	A();
	~A();
};

class B : public Base
{
private:
public:
	B();
	~B();
};

class C : public Base
{
private:
public:
	C();
	~C();
};

/*
Implement the following functions:
Base * generate(void);
It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
to use anything you like for the random choice implementation.
void identify(Base* p);
It prints the actual type of the object pointed to by p: "A", "B" or "C".
void identify(Base& p);
It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
inside this function is forbidden.
Including the typeinfo header is forbidden.
Write a program to test that everything works as expected.
*/


#endif
