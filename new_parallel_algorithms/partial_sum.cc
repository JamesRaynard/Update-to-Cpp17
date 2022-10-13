#include <numeric>
#include <iostream>
#include <vector>

int main()
{
	std::vector vec{1, 2, 3, 4};
	std::vector vec2(vec.size());

	// vec2 will contain { 1, 3, 6, 10 };
	std::partial_sum(begin(vec), end(vec), begin(vec2));

	std::cout << "Original vector elements: ";
	for (auto i : vec)
		std::cout << i << ", ";

	std::cout << "\nPartial sum vector elements: ";
	for (auto i : vec2)
		std::cout << i << ", ";
	std::cout << '\n';
}