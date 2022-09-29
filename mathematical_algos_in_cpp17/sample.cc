#include <random>
#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>

int main()
{
	std::vector<int> vec(1'000'000);                  // Create a vector with 1 million elements
	std::iota(begin(vec), end(vec), 1);               // Populate the elements as 1, 2, 3, 4, ...
	
	std::vector<int> res;                             // Vector to store the selected elements
	
	// Select 10 elements from vec and append them to res
	std::sample(begin(vec), end(vec), back_inserter(res), 10, std::mt19937());
	
	std::cout << "Ten elements randomly selected from vec: ";
	
	// Loop over the selected elements
	for (auto r : res)
		std::cout << r << ", ";
	std::cout << '\n';
}