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
    
	// Call the lambda expression on every element of vec
    std::for_each(begin(vec), end(vec), [](auto& n) { n += 2; });
	
	std::cout << "Vector elements: ";
	for (auto v : vec)
		std::cout << v << ", ";
	std::cout << '\n';
}