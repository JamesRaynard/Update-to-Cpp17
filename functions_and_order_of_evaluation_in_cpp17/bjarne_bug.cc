#include <iostream>
#include <string>

int main()
{
	std::string s = "but I have heard it works even if you don't believe in it";
	std::cout << s << "\n";
	
	// In C++17, this code now has well-defined behaviour
	s.replace(0, 4, "").replace(s.find("even"), 4, "only").replace(s.find(" don't"), 6, "");
	std::cout << s << "\n";
}