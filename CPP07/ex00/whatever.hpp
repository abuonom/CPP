#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &arg1, T &arg2)
{
	T temp;
	temp = arg1;
	arg1 = arg2;
	arg2 = temp;
}
template <typename T>
T min(T &arg1, T &arg2)
{
	if (arg1 < arg2)
		return arg1;
	return arg2;
}
template <typename T>
T max(T &arg1, T &arg2)
{
	if (arg1 > arg2)
		return arg1;
	return arg2;
}
/*
swap: Swaps the values of two given arguments. Does not return anything.
•min: Compares the two values passed in its arguments and returns the smallest
one. If the two of them are equal, then it returns the second one.
•max: Compares the two values passed in its arguments and returns the greatest one.
If the two of them are equal, then it returns the second one.
*/
#endif
