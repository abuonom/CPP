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
	(void)toCopy;
	return *this;
}

int RPN::operation()
{
	char *token = strtok(const_cast<char *>(this->expression.c_str()), " ");
	int num_left;
	int num_right;
	while (token)
	{
		if (isdigit(*token))
			num.push(atoi(token));
		else
		{
			if ((strchr("+-*/", *token) == NULL) && num.size() != 2)
				throw rpnException();
			num_right = num.top();
			num.pop();
			num_left = num.top();
			num.pop();
			switch (*token)
			{
			case '+':
				num.push(num_left + num_right);
				break;

			case '-':
				num.push(num_left - num_right);
				break;

			case '*':
				num.push(num_left * num_right);
				break;

			case '/':
				if (num_right != 0)
					num.push(num_left / num_right);
				else
					throw ZeroException();
				break;

			default:
				throw rpnException();
			}
		}
		token = strtok(NULL, " ");
	}
	if (num.size() != 1)
		throw rpnException();
	return num.top();
}
