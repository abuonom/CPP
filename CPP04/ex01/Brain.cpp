#include "Brain.hpp"

Brain::Brain()
{
	for(int i = 0; i<100;i++)
		ideas[i] = "Forza Napoli Sempre";
	std::cout<<"Brain created with default constructor"<<std::endl;
}

Brain::Brain(const Brain &toCopy)
{
	if(this != &toCopy)
		*this = toCopy;
	std::cout<<"Brain created with copy constructor"<<std::endl;
}

Brain& Brain::operator=(const Brain &tocopy)
{
	for(int i = 0; i<100;i++)
		this->ideas[i] = tocopy.ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout<<"Brain destruct"<<std::endl;
}

void Brain::setIdea(int index, std::string idea)
{
	this->ideas[index] = idea;
}

std::string Brain::getIdea(int index)
{
	return ideas[index];
}
