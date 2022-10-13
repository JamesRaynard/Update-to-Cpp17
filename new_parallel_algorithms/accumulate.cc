#include <numeric>
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec{1, 2, 3, 4, 5, 6, 7};

	// Sum elements using initial value 0
	auto sum = std::accumulate(begin(vec), end(vec), 0);

	std::cout << "Vector elements: ";
	for (auto i : vec)
		std::cout << i << ", ";
	std::cout << "\nSum of elements is " << sum << '\n';
}