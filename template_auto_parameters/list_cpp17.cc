#include <iostream>

template <auto... args>
struct HeterogenousValueList {};

using Numbers = HeterogenousValueList<1, '2', 3u>;

int main()
{
	Numbers numbers;
}