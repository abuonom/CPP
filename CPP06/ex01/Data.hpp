#ifndef DATA_HPP
#define DATA_HPP

class Data
{
private:
	int data;

public:
	Data(int data);
	Data(Data const &toCopy);
	Data &operator=(Data const &toCopy);
	bool operator==(const Data& other) const;
	~Data();
};
#endif
