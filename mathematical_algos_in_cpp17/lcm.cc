#include <iostream>
#include <numeric>

int main()
{
	int x{9};
	int y{15};

	// Find the Lowest Common Multiplier of 9 and 15
	std::cout << "The LCM of " << x << " and " << y << " is " << std::lcm(x, y) << '\n';
}