#include <numeric>
#include <iostream>
#include <execution>
#include <vector>

// A convenient alias
namespace se = std::execution;

int main()
{
	std::vector vec{1, 2, 3, 4};
	std::vector<int> vec2(vec.size());

	// Equivalent to std::inclusive_scan of {-1, 1, 2, 3}
	std::exclusive_scan(se::par_unseq, begin(vec), end(vec), begin(vec2), -1);

	std::cout << "Original vector elements: ";
	for (auto i : vec)
		std::cout << i << ", ";

	std::cout << "\nExclusive scan vector elements: ";
	for (auto i : vec2)
		std::cout << i << ", ";
	std::cout << '\n';
}