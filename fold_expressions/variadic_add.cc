#include <iostream>
#include <string>

using namespace std::literals;

// Single-argument function to terminate the recursion
template <typename T>
T add(const T& t)
{
	return t;
}

// Recursive function which adds the first element to the sum
template <typename T, typename... Args>
T add(const T& t, Args... args)
{
	return t + add(args...);           // "Left fold" expression - evaluated from left to right
}

int main()
{
	std::cout << "add(1, 2, 3, 4, 5, 6, 7, 8) gives " << add(1, 2, 3, 4, 5, 6, 7, 8) << '\n';
	std::cout << R"(add("1"s, "2"s, "3"s, "4"s) gives )" << add("1"s, "2"s, "3"s, "4"s) << '\n';
}