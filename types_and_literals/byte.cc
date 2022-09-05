#include <iostream>
#include <cstddef>
//#include <cstring> // For tolower()

int main()
{
	std::byte b{42};
	std::cout << "b: " << std::to_integer<int>(b) << "\n";
	
	std::cout << "Performing b <<= 2\n";
	b <<= 2;
	
	std::cout << "b: " << std::to_integer<int>(b) << "\n";
	
	//++b;                    // Error!
	//std::tolower(b);        // Error!
}