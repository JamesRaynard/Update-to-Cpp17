#include <iostream>
#include <filesystem>

// A convenient namespace alias
namespace fs = std::filesystem;

int main()
{
	// Create a path object
	//fs::path test_file("D:\\test\\test.txt");
	fs::path test_file("D:\\temp\\test.txt");
	std::cout << "test_file path is " << test_file << '\n';
	
	// fs::file_size throws fs::filesystem_error if fs::file_size() fails
	try {
		std::cout << "Size of the file: " << fs::file_size(test_file) << " bytes\n";
	}
	catch(std::exception& e) {
		std::cout << "Could not get file size: " << e.what() << '\n';
	}
}