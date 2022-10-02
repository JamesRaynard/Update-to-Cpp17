#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>

// A convenient namespace alias
namespace fs = std::filesystem;
using namespace std::literals;

int main()
{
	// Create a file to work with
	std::string filename("D:/temp/test.txt");
	std::ofstream test(filename);                    // Create the file
	test.close();                                    // Cannot delete or move open files on Windows!

	// Create a path object
	fs::path test_path(filename);
	std::cout << "The test file path is " << test_path << "\n\n";

	// Convert the path to use the "system preferred" directory separators
	// "/" on Unix
	// "\" on Windows (use "\\" because "\" is the escape character)
	std::cout << "Calling make_preferred\n";
	test_path.make_preferred();
	std::cout << "The test file path is now " << test_path << "\n\n";

	// Change the file extension in the path object
	std::cout << "Calling replace_extension\n";
	test_path.replace_extension(".bak");
	std::cout << "The test file path is now " << test_path << "\n\n";

	// Change the file name in the path object
	std::cout << "Calling replace_filename\n";
	test_path.replace_filename("test2.txt");
	std::cout << "The test file path is now " << test_path << "\n\n";
	
	// Change the name of the file on disk
	std::cout << "Renaming D:/test.txt to D:/test2.txt" << "\n\n";
	fs::rename(filename, test_path);                      // D:/test.txt becomes D:/test2.txt

	// Delete the file
	std::cout << "Calling remove_filename\n";
	test_path.remove_filename();
	std::cout << "The test file path is now " << test_path << '\n';
}