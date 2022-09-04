#include <iostream>
#include <utility>

// Two overloaded functions
// This one leaves its argument unmodified
void func(const double&)
{
	std::cout << "Calling func with const& argument\n";
}

// This overload modifies its argument
void func(double&)
{
	std::cout << "Calling func with non-const& argument\n";
}

int main()
{
	double d{5.0};
	func(d);                       // Calls non-const version

	double const cd = 5.0;
	func(cd);                      // Calls const version

	// Protect d from being accidentally modified
	func(std::as_const(d));        // Forces call of const version
}