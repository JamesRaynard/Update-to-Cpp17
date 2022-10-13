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

	// vec2 will contain { 1, 3, 6, 10 };
	std::inclusive_scan(se::par_unseq, begin(vec), end(vec), begin(vec2));

	std::cout << "Original vector elements: ";
	for (auto i : vec)
		std::cout << i << ", ";

	std::cout << "\nInclusive scan vector elements: ";
	for (auto i : vec2)
		std::cout << i << ", ";
	std::cout << '\n';
}