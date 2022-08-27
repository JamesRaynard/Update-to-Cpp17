#include <iostream>

int main()
{
	int n = 1;
	
	// Equivalent to operator << (operator <<(std::cout, n), ++n);
	//std::cout << n << ++n;
	
	// Could display "n = 1, ++n = 2" or "n = 2, ++n = 2"
	std::cout << "n = " << n << ", ++n = " << ++n << '\n';
}