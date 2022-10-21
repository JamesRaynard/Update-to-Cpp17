#include <iostream>

// Variable to represent a constant of a given type
// The type needs to be given as a type parameter
template <typename Type, Type value>
constexpr Type constant = value;

// The type also needs to be given as a type parameter when instantiating
constexpr auto const IntConstant42 = constant<int, 42>;

int main()
{
	std::cout << "IntConstant42 = " << IntConstant42 << '\n';
}