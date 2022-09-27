#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std::literals;

int main()
{
	//std::vector<int> vec{1, 2, 3};                               // C++14
	std::vector vec{1, 2, 3};                                      // C++17

	//std::map<std::string, int> scores = { {"Graham"s, 66} };     // C++14
	std::map scores = { std::pair{"Graham"s, 66}  };               // C++17
}