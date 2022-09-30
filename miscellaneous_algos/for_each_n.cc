#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec{3, 1, 4, 1, 5, 9};
    
	std::cout << "Vector elements: ";
	for (auto v : vec)
		std::cout << v << ", ";
	std::cout << '\n';
    
	// Call the lambda expression on the first three elements of vec
    std::for_each_n(begin(vec), 3, [](auto& n) { n += 2; });
	
	std::cout << "Vector elements: ";
	for (auto v : vec)
		std::cout << v << ", ";
	std::cout << '\n';
}