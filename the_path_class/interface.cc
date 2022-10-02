#include <iostream>
#include <filesystem>

// A convenient namespace alias
namespace fs = std::filesystem;

int main()
{
	// Create a path object
	fs::path test_file{"D:/temp/test.txt"};
	std::cout << "test_file path is " << test_file << '\n';

	// Use member functions to analyze the path
	std::cout << "exists = " << std::boolalpha << exists(test_file) << '\n';
	std::cout << "is_regular_file = " << std::boolalpha << is_regular_file(test_file) << '\n';
	std::cout << "root_name = " << test_file.root_name() << '\n';
	std::cout << "root_path = " << test_file.root_path() << '\n';
	std::cout << "relative_path = " << test_file.relative_path() << '\n';
	std::cout << "parent_path = " << test_file.parent_path() << '\n';
	std::cout << "filename = " << test_file.filename() << '\n';
	std::cout << "stem = " << test_file.stem() << '\n';
	std::cout << "extension = " << test_file.extension() << '\n';
}