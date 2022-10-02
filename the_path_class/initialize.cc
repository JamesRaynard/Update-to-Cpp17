#include <iostream>
#include <filesystem>
#include <fstream>

// A convenient namespace alias
namespace fs = std::filesystem;

int main()
{
	// Create a file to work with
	std::string filename("D:/temp/test.txt");
	std::ofstream test(filename);                    // Create the file
	test.close();

	// Create an fs::path object
	fs::path test_file{"D:/temp/test.txt"};
	std::cout << "test_file path is " << test_file << '\n';

	// Use the path object to open the file
	std::ifstream ifile{test_file};
	if (ifile)
		std::cout << "Opened " << test_file << " for reading\n";
	else
		std::cout << "Could not open " << test_file << " for reading\n";
}