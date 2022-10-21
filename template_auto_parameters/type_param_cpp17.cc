#include <iostream>

// Variable to represent a constant of a given type
// The type can be auto in C++17
template <auto value>
constexpr auto constant = value;

// The type will be deduced when the template is instantiated
constexpr auto const IntConstant42 = constant<42>;

int main()
{
	std::cout << "IntConstant42 = " << IntConstant42 << '\n';
}