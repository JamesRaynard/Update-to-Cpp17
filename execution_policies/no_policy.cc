#include <algorithm>
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> vec(2000);
	int count {0};
	
	// vec -> {1, 2, ..., 2000}
	std::for_each(begin(vec), end(vec),
				  [&] (int& x) { x = ++count; }
				  );

	for (auto v : vec)
		std::cout << v << ", ";
}