#include <iostream>
#include <filesystem>

// A convenient namespace alias
namespace fs = std::filesystem;

int main()
{
	// Create a path object
	fs::path test_file("D:\\temp\\test.txt");
	std::cout << "test_file path is " << test_file << '\n';
	
	// Get the size of the file in bytes
	std::cout << "Size of the file: " << fs::file_size(test_file) << " bytes\n";
}