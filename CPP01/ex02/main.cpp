#include <string>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str; //PUNTATORE: punta all'indirizzo di str
	std::string& stringREF = str; //REFERENCE: è una copia di str, non può essere NULL

	std::cout<<"STR Memory adress: "<<&str<<std::endl;
	std::cout<<"stringPTR Memory adress: "<<stringPTR<<std::endl;
	std::cout<<"stringREF Memory adress: "<<&stringREF<<std::endl;

	std::cout<<"STR Value: "<<str<<std::endl;
	std::cout<<"stringPTR point to: "<<*stringPTR<<std::endl;
	std::cout<<"stringREF point to: "<<stringREF<<std::endl;
}
