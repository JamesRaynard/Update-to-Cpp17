#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

int main()
{
	std::string str{"Feh"};
	std::string str1{"abcdef"};
	std::string str2{"ghij"};

	std::cout << "str = " << str << ", str1 = " << str1 << ", str2 = " << str2 << '\n';

	// Case-sensitive clamp() for std::string
	auto ret = std::clamp(str, str1, str2);
	std::cout << "clamp(str, str1, str2) returns " << ret << '\n';

	// Case-insensitive clamp() for std::string
	auto ret2 = std::clamp(str, str1, str2,
		// Predicate for std::clamp()
		// Performs case-insensitive string comparison
		[](const std::string& s1, const std::string& s2) {
			return std::lexicographical_compare(begin(s1), end(s1), begin(s2), end(s2),
				[](char lc, char rc) {
					return std::toupper(lc) < std::toupper(rc);
				}
			);
		}
	);

	std::cout << "clamp with predicate returns " << ret2 << '\n';
}