#include <iostream>
#include <numeric>

int main()
{
	int x{36};
	int y{60};

	// Find the Greatest Common Denominator of x and y
	std::cout << "The GCD of " << x << " and " << y << " is " << std::gcd(x, y)<< '\n';
}