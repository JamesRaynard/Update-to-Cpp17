#include <iostream>
#include <map>
#include <algorithm>

using namespace std::literals;

// Function to display map elements
void print(const std::map<std::string, int>& scores) {
	for (auto score : scores)
		std::cout << "Key = " << score.first << ", value = " << score.second << '\n';
}
int main() {
	std::map<std::string, int> old_scores = { {"Graham"s, 66}, {"Maybelline"s, 86} };
	std::map<std::string, int> new_scores = { {"Graham"s, 78}, {"Grace"s, 66}, {"Hareesh"s, 77} };
	
	std::cout << "Old scores:\n";
	print(old_scores);
	
	std::cout << "New scores:\n";
	print(new_scores);
	
	// Merge old scores into new scores
	std::cout << "\nMerging scores\n";
	
	// Destination object for results
	std::map<std::string, int> dest;
	
	// Call std::merge()
	std::merge(begin(old_scores), end(old_scores), begin(new_scores), end(new_scores),
		       inserter(dest, begin(dest)));
	
	// Get the results into new_scores
	std::swap(dest, new_scores);
	
	std::cout << "Old scores:\n";
	print(old_scores);
	
	std::cout << "New scores:\n";
	print(new_scores);
}