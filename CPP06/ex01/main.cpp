#include <iostream>
#include "Serializer.hpp" // Include the header file for your Serializer class

int main()
{

	Data originalData(42);

	uintptr_t serializedData = Serializer::serialize(&originalData);

	Data *deserializedData = Serializer::deserialize(serializedData);

	if (deserializedData != NULL && *deserializedData == originalData)
	{
		std::cout << "Serialization and deserialization successful!" << std::endl;
	}
	else
	{
		std::cout << "Serialization or deserialization failed!" << std::endl;
	}
	return 0;
}
