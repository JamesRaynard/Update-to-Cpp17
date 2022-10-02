#include <iostream>
#include <filesystem>

// A convenient namespace alias
namespace fs = std::filesystem;

int main()
{
	// Use member functions to compose a path
	fs::path drive_path{"D:\\"};
	fs::path test_file = drive_path;
	test_file.append("temp");
	test_file /= ("test");
	test_file += ".txt";
		
	std::cout << test_file << '\n';
}