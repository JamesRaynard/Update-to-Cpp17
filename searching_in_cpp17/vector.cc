#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

void print(const std::vector<int>& vec)
{
	for (auto v : vec)
		std::cout << v << ", ";
}
int main()
{
	std::vector vec{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 3, 2, 3, 8, 4, 6, 2, 6, 4, 3, 3, 8};
	std::cout << "Vector to search: ";
	print(vec);
	std::cout << '\n';

	std::vector needle{2, 3};
	std::cout << "Searching for : ";
	print(needle);
	std::cout << '\n';

	std::boyer_moore_searcher src{begin(needle), end(needle)};

	// Returns an iterator to the first element of {2, 3}
	auto pos = std::search(cbegin(vec), cend(vec), src);

	if (pos != cend(vec)) {
		std::cout << "Found ";
		print(needle);
		std::cout << " starting at index " << distance(cbegin(vec), pos) <<'\n';
	}
}
