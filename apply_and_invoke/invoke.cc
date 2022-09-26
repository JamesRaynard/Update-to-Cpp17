#include <iostream>
#include <functional>
#include <string>

using namespace std::literals;

void func(int i, double d, std::string s) {
	std::cout << "i = " << i << ", d = " << d << ", s = " << s << '\n';
}

int main()
{
	std::invoke(func, 1, 2.0, "three"s);                // Calls func(1, 2.0, "three"s);
}