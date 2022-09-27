#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std::literals;

int main()
{
	std::vector vec{1, 2, 3};                     // Define a vector
	
	std::cout << "Vector elements: ";
	for (auto v : vec)
		std::cout << v << ", ";
	std::cout << "\n";
	
	std::cout << std::boolalpha << "Vector is empty: " << empty(vec) << "\n";
	std::cout << "Number of elements in vector: " << size(vec) << "\n\n";
	
	int *pvec = data(vec);                           // Get the vector's internal data as an array
	std::cout << "Array elements: ";
	for (int i = 0; i < size(vec); ++i)
		std::cout << pvec[i] << ", ";
	std::cout << "\n";
	
	std::map scores = { std::pair{"Graham"s, 66}  };
	std::cout << std::boolalpha << "Map is empty: " << empty(scores) << "\n";
	std::cout << "Number of elements in map: " << size(scores) << "\n";
	
	// map::data() does not exist
	//int *pmap = data(scores);                               // Error! No matching function
}