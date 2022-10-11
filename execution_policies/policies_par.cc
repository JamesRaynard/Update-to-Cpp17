#include <algorithm>
#include <vector>
#include <iostream>
#include <execution>

// A convenient alias
namespace se = std::execution;

int main()
{
	std::vector<int> vec(2000);
	int count {0};
	
	// Data race!
	std::for_each(se::par, begin(vec), end(vec),
                           [&] (int& x) { x = ++count; }
						   );

	for (auto v : vec)
		std::cout << v << ", ";
}