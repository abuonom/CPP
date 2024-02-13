#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <stdint.h>
#include "Data.hpp"

/*
Per questo esercizio studierò:
"reinterpret_cast"
Consente a qualsiasi puntatore di essere convertito in un qualsiasi altro tipo di puntatore.
Consente inoltre a qualsiasi tipo integrale di essere convertito in qualsiasi tipo di puntatore e viceversa.
*/

class Serializer
{
private:
	Serializer(/* args */);
	~Serializer();
	Serializer(Serializer const &toCopy);
	Serializer &operator=(Serializer const &toCopy);
public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};
#endif
