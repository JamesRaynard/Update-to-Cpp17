#include <iostream>
#include <map>

// Function to display map elements
void print(const std::map<std::string, int>& scores)
{
	for (auto score : scores)
		std::cout << "Key = " << score.first << ", value = " << score.second << "\n";
}

int main()
{
	std::map<std::string, int> old_scores = { {"Graham", 66}, {"Maybelline", 86} };
	std::map<std::string, int> new_scores = { {"Graham", 78}, {"Grace", 66}, {"Hareesh", 77} };
	
	std::cout << "Old scores:\n";
	print(old_scores);
	
	std::cout << "New scores:\n";
	print(new_scores);
	
	// Merge old scores into new scores
	std::cout << "\nMerging scores\n";
	
	// Iterate over old_scores
	// Insert each element into new_scores
	// Duplicates will be ignored
	for (auto score : old_scores)
		new_scores.insert(score);
	
	std::cout << "Old scores:\n";
	print(old_scores);
	
	std::cout << "New scores:\n";
	print(new_scores);
}