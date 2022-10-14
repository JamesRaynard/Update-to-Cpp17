#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec{1, 2, 3, 4};
	std::vector<int> vec2;
	std::transform(begin(vec), end(vec),
	               back_inserter(vec2),
        	       [] (int n) {return 2*n;}
	);
	
	std::cout << "Input vector:  ";
	for (auto i : vec)
		std::cout << i << ", ";
	
	std::cout << "\nOutput vector: ";
	for (auto i : vec2)
		std::cout << i << ", ";
	std::cout << '\n';
}