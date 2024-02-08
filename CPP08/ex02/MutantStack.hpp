#include <stack>

template <typename T, typename container_type = std::deque<T> >
class MutantStack : public std::stack<T>
{
private:

public:
	typedef typename container_type::iterator iterator;
	MutantStack()
	{

	}

	~MutantStack()
	{

	}

	iterator begin()
	{
		return this->c.begin();
	}

	iterator end()
	{
		return this->c.end();
	}

};
