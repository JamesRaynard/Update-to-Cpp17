#include <variant>
#include <exception>
#include <iostream>

// Struct whose conversion operator throws
struct Thrower {
	int i{0};
	operator int() {
		throw std::out_of_range("Ouch!");
		return i;
	}
};

int main()
{
	// Initialize with int alternative in use, value with 0
	std::variant<int, double> var;

	try {
		// emplace() calls Thrower's conversion operator
		// The conversion operator throws an exception
		// The construction of the int alternative fails
		// Some alternatives seem to restore the previous value

		// Operation which may invalidate the variant if it throws
		var.emplace<0>(Thrower());
	}
	catch (std::exception& e) {
		std::cout << "Calling valueless_by_exception()\n";

		// Displays "true" with Visual C++, "false" with g++
		std::cout << std::boolalpha << var.valueless_by_exception() << "\n";
	}
	try {
		std::cout << "var<0>: " << std::get<0>(var);
	}
	catch (std::exception& e) {
		std::cout << "Caught an exception: " << e.what() << '\n';
	}
}