#include <iostream>
#include <map>
#include <string>

int main()
{
	std::map<std::string, int> scores = {{"Graham", 66}};   // Create an std::map object
	std::multimap<std::string, int> scores2 = {};           // Create an std::multimap object

	std::cout << "Scores Map:\n";
	for (auto score : scores)
		std::cout << "Key = " << score.first << ", value = " << score.second << '\n';

	std::cout << "Scores Multimap:\n";
	for (auto score : scores2)
		std::cout << "Key = " << score.first << ", value = " << score.second << '\n';

	// Change key of "Graham" element
	auto node = scores.extract("Graham");                     // Unlink the element from the tree

	if (node) {                                               // Check that we have an element
		scores2.insert(std::move(node));                       // Re-insert the element
	}

	std::cout << "Scores Map:\n";
	for (auto score : scores)
		std::cout << "Key = " << score.first << ", value = " << score.second << '\n';

	std::cout << "Scores Multimap:\n";
	for (auto score : scores2)
		std::cout << "Key = " << score.first << ", value = " << score.second << '\n';
}
