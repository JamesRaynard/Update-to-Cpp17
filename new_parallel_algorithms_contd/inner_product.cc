#include <numeric>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	std::vector x{1, 2, 3, 4, 5};
	std::vector y{5, 4, 3, 2, 1};

	auto result = std::inner_product(begin(x), end(x),      // Iterator range for first vector
                                               begin(y),   // Start of second vector
                                               0);         // Initial value of sum
	
	std::cout << "First vector:  ";
	for (auto i : x)
		std::cout << i << ", ";
	
	std::cout << "\nSecond vector: ";
	for (auto i : y)
		std::cout << i << ", ";
	std::cout << "\n";
	
	std::cout << "Result is " << result << "\n";            // Displays 35
}