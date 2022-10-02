#include <iostream>
#include <filesystem>

// A convenient namespace alias
namespace fs = std::filesystem;

int main()
{
	fs::path test_file("D:\\temp\\test.txt");
	std::cout << "The file path is " << test_file << '\n';

	std::cout << "The elements of the file path are:\n";

	// fs::path supports iterators
	std::cout << "Using explicit loop:\n";
	for (fs::path::iterator iter = test_file.begin(); iter != test_file.end(); ++iter)
		std::cout << *iter << '\n';
	
	std::cout << "Using range-for loop:\n";
	// Use a range-for loop to iterate over the elements of the path
	for (const auto& element : test_file)
		std::cout << element << '\n';
}