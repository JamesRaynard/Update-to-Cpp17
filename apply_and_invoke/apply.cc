#include <iostream>
#include <tuple>
#include <string>

using namespace std::literals;

void func(int i, double d, std::string s)
{
	std::cout << "i = " << i << ", d = " << d << ", s = " << s << '\n';
}

int main()
{
	std::tuple<int, double, std::string>  numbers(1, 2.0, "three"s);
	std::apply(func, numbers);             // Calls func(1, 2.0, "three"s);
}