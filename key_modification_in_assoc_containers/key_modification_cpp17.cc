#include <iostream>
#include <map>
#include <string>

int main()
{
	std::map<std::string, int> scores = { {"Graham", 66} };   // Create an std::map object
	
	std::cout << "Original map\n";
	for (auto score : scores)
		std::cout << "Key = " << score.first << ", value = " << score.second << '\n';

	// Change key of "Graham" element
	std::cout << "Changing key to Grace\n";
	auto node = scores.extract("Graham");                     // Unlink the element from the tree
	
	if (node) {                                               // Check that we have an element
		node.key() = "Grace";                                 // Change the key
		scores.insert(std::move(node));                       // Re-insert the element
	}
	
	for (auto score : scores)
		std::cout << "Key = " << score.first << ", value = " << score.second << '\n';
}
