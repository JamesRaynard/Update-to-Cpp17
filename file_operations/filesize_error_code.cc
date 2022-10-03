#include <iostream>
#include <filesystem>
#include <system_error>

// A convenient namespace alias
namespace fs = std::filesystem;

int main()
{
	// Create a path object
	//fs::path test_file("D:\\test\\test.txt");
	fs::path test_file("D:\\temp\\test.txt");
	std::cout << "test_file path is " << test_file << '\n';
	
	// Overload of fs::file_size which takes an error code
	auto err = std::error_code{};
	auto size = fs::file_size(test_file, err);

	if (err)
		std::cout << "Could not get file size: " << err.message() << '\n';
	else
		std::cout << "Size of the file: " << size << " bytes\n";
}