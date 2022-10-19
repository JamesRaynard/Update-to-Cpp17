#include <string>
#include <iostream>

using namespace std::literals;

// Return true if all arguments evaluate to true, otherwise false
template <typename... Args>
bool all_of(Args... args)
{
	return (... && args);    // Left fold
	// Equivalent to ((args1 && args2) && args3)
}

// Return true if any argument evaluates to true, otherwise false
template <typename... Args>
bool any_of(Args... args)
{
	return (... || args);    // Left fold
	// Equivalent to ((args1 || args2) || args3)
}

// Return true if no argument evaluates to true, otherwise false
template <typename... Args>
bool none_of(Args... args)
{
	return (... && !args);    // Left fold
	// Equivalent to (!args && (!args2 && !args3))
}

int main()
{
	std::cout << std::boolalpha;
	std::cout << "any_of(1 == 1, 1 == 2) returns " << any_of(1 == 1, 1 == 2) << '\n';
	std::cout << "all_of(1 == 1, 1 == 2) returns " << all_of(1 == 1, 1 == 2) << '\n';
	std::cout << "none_of(1 == 1, 1 == 2) returns " << none_of(1 == 1, 1 == 2) << '\n';
}