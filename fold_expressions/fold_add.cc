#include <iostream>
#include <string>

using namespace std::literals;

template <typename... Args>
auto add(Args... args)
{
	return (... + args);
}

int main()
{
	std::cout << "add(1, 2, 3, 4, 5, 6, 7, 8) gives " << add(1, 2, 3, 4, 5, 6, 7, 8) << '\n';
	std::cout << R"(add("1"s, "2"s, "3"s, "4"s) gives )" << add("1"s, "2"s, "3"s, "4"s) << '\n';
}