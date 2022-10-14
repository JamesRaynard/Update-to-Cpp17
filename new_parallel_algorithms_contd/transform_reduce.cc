#include <numeric>
#include <iostream>
#include <execution>
#include <vector>

// A convenient alias
namespace se = std::execution;

int main()
{
	std::vector x{1, 2, 3, 4, 5};
	std::vector y{5, 4, 3, 2, 1};

	auto result = std::transform_reduce(se::par_unseq,       // Parallel execution
	                                    begin(x), end(x),    // Iterator range for first vector
                                        begin(y),            // Start of second vector
                                        0);                  // Initial value of sum
	
	std::cout << "First vector:  ";
	for (auto i : x)
		std::cout << i << ", ";
	
	std::cout << "\nSecond vector: ";
	for (auto i : y)
		std::cout << i << ", ";
	std::cout << '\n';
	
	std::cout << "Result is " << result << '\n';             // Displays 35
}