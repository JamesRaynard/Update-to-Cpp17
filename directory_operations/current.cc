#include <iostream>
#include <fstream>
#include <filesystem>
 
// A convenient namespace alias
namespace fs = std::filesystem;
 
int main() {
	auto original_path = fs::current_path();    // Store the initial working directory
	std::cout << "Current working directory is: " << original_path << '\n';
	
	fs::path temp{"temp"};
	fs::create_directory(temp);                // Create a subdirectory "temp" in the current directory
	std::ofstream tempfile("temp/test.txt");    // Create a file in temp
	fs::create_directory("temp/temp1");        // Create a subdirectory temp1 of temp
	
	std::cout << "\nChanging working directory to temp\n";
	fs::current_path(temp);
	std::cout << "Current working directory is: " << fs::current_path() << '\n';
	
	fs::directory_iterator dir{"."};
	
	std::cout << "\nThe current working directory contains:\n";
	// Iterate over all the directory entries in temp
	for (const auto& entry: dir) {
        std::cout << entry << '\n';
	}
	
	tempfile.close();
	
	std::cout << "\nChanging working directory back to the original path\n";
	fs::current_path(original_path);
	std::cout << "Current working directory is: " << original_path << '\n';
	
	// Delete temp and all its contents
	remove_all(temp);
}