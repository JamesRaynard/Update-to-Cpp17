#include <string>
#include <iostream>
#include <algorithm>
#include <functional>

int main()
{
	std::string str {"Peter Piper picked a peck of pickled peppers"};
	std::cout << "String to search: " << str << '\n';
	
	std::string needle{"pepper"};
	std::cout << "Searching for needle : " << needle << '\n';
	
	std::boyer_moore_searcher src{begin(needle), end(needle)};
	
	// Returns an iterator to the first character of "pepper"
	auto pos = std::search(cbegin(str), cend(str), src);
	
	if (pos != cend(str))
		std::cout << "Found " << needle << " starting at index " << distance(cbegin(str), pos) << '\n';
}
