#include <iostream>
#include <string>
#include <tuple>

using namespace std::literals;

// Our custom type
struct Test {
	int i;
	double d;
	std::string s;
};

// Implement get<idx> for our type
template<int Idx>
auto constexpr get(const Test& test)            // Function returning "auto"
{
	if constexpr (Idx == 0)            // Return the value which corresponds to the index
		return test.i;
	else if constexpr (Idx == 1)
		return test.d;
	else if constexpr (Idx == 2)
		return test.s;
}

Test func()  // Function that returns a Test object
{
	return {1, 2.0, "three"s};
}

void func(const Test& test)
{
	auto& [n, x, str] = test;
	std::cout << "In func(): n = " << n << ", x = " << x << ", str = " << str << "\n\n";
}

int main()
{
	std::cout << "Getting a Test object by calling func()\n";
	auto [n, x, str] = func(); // Types are int, double, and std::string
	std::cout << "From func(): n = " << n << ", x = " << x << ", str = " << str << "\n\n";

	std::cout << "Passing a Test object to func()\n";
	Test test{1, 2.0, "three"s};
	func(test);
}