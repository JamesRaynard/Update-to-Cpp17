#include <string>
#include <iostream>
#include <algorithm>

int main()
{
	std::string str {"Peter Piper picked a peck of pickled peppers"};
	std::cout << "String to search: " << str << '\n';
	
	std::string needle{"pepper"};
	std::cout << "Searching for needle : " << needle << '\n';
	
	// Returns an iterator to the first character of "pepper"
	auto pos = std::search(cbegin(str), cend(str), cbegin(needle), cend(needle));
	
	if (pos != cend(str))
		std::cout << "Found " << needle << ", starting at index " << distance(cbegin(str), pos) << '\n';
}
