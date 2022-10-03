#include <iostream>
#include <filesystem>

// A convenient namespace alias
namespace fs = std::filesystem;

int main()
{
	fs::path test_file("D:\\temp\\test.txt");
	std::cout << "test_file path is " << test_file << "\n";
	
	// In C++17, ,we can get the last write time, be we cannot portably do anything with it
	// std::cout << "Last write time: " << fs::last_write_time(test_file) << " bytes\n";
}