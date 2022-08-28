#include <iostream>

int main()
{
	int n = 1;
	
	// Equivalent to operator << (operator <<(std::cout, n), ++n);
	//std::cout << n << ++n;
	
	// In C++17, this code now has well-defined behaviour
	std::cout << "n = " << n << ", ++n = " << ++n << '\n';
}