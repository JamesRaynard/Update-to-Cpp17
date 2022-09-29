#include <iostream>
#include <algorithm>

int main() {
	int x{7};
	int y{1};
	int z{10};
	
	// Force x to be >= y and <= z
	std::cout << "std::clamp(" << x  << ", " << y << ", " << z << ") returns "
              << std::clamp(x, y, z) << '\n';
}