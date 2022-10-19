#include <iostream>
#include <string>

using namespace std::literals;

template <typename... Args>
std::ostream& print(std::ostream& os, Args... args)
{
	return (os << ... << args);
}

int main()
{
	std::cout << R"(print(1, ", ", 2, ", ", 3, ", ", 4):)" << '\n';
	print(std::cout, 1, ", ", 2, ", ", 3, ", ", 4) << '\n';
	std::cout << R"(print("1"s, ", ", "2"s, ", ", "3"s, ", ", "4"s):)" << '\n';
	print(std::cout, "1"s, ", ", "2"s, ", ", "3"s, ", ", "4"s) << '\n';
}