#include "RPN.hpp"
#include <stack>


RPN::RPN(std::string expression)
{
	this->expression = expression;
}
RPN::~RPN()
{

}
RPN::RPN(const RPN &toCopy)
{
	*this = toCopy;
}

RPN &RPN::operator=(const RPN &toCopy)
{
	(void) toCopy;
	return *this;
}

int RPN::operation()
{
	char *token = strtok(const_cast<char*>(this->expression.c_str()), " ");
}
