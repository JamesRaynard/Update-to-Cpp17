#include <numeric>
#include <iostream>
#include <vector>
#include <execution>

// A convenient alias
namespace se = std::execution;

int main()
{
	std::vector vec{1, 2, 3, 4, 5, 6, 7};

	// Sum elements of vec using initial value 0
	auto sum = std::reduce(se::par_unseq, begin(vec), end(vec), 0);

	std::cout << "Vector elements: ";
	for (auto i : vec)
		std::cout << i << ", ";
	std::cout << "\nSum of elements is " << sum << '\n';
}