#include <iostream>
#include <map>
#include <string>

int main()
{
	std::map<std::string, int> scores = { {"Graham", 66} };    // Create an std::map object
	
	std::cout << "Original map\n";
	for (auto score : scores)
		std::cout << "Key = " << score.first << ", value = " << score.second << '\n';

	// Change key of "Graham" element
	std::cout << "Changing key to Grace\n";
	auto iter = scores.find("Graham");
	if (iter != end(scores)) {
		auto value = iter->second;                             // Save the original value
		scores.erase(iter);                                    // Erase the element
		scores.insert(std::make_pair("Grace", value));         // Insert a new element with the new key
	}
	
	for (auto score : scores)
		std::cout << "Key = " << score.first << ", value = " << score.second << '\n';
}
