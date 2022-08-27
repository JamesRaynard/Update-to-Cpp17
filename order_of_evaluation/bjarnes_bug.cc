#include <iostream>
#include <string>

int main()
{
	// The result is intended to be
	// "I have heard it works only if you believe in it"

	std::string s = "but I have heard it works even if you don't believe in it";

	//s.replace(0, 4, "").replace(s.find("even"), 4, "only").replace(s.find(" don't "), 6, "");

	std::cout << s << "\n";

	// The replace() function calls are made in left-to-right order
	// However, the find() calls can be made in any order

	// For example:
	int dont = s.find(" don't ");
	s.replace(0, 4, "");
	int even = s.find("even");
	s.replace(even, 4, "only");
	s.replace(dont, 6, "");

	std::cout << s << '\n';
}