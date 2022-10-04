#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

// A convenient namespace alias
namespace fs = std::filesystem;
 
void show_status(const fs::path& path)
{
	// Get the file's status
	fs::file_status stat = fs::status(path);
	
	// Does this file exist?
	if(!fs::exists(stat)) {
		std::cout << path << " does not exist\n";
		return;
	}
	
	// Get some information about the file
    if(fs::is_regular_file(stat))
		std::cout << path << " is a regular file\n";
    if(fs::is_directory(stat))
		std::cout << path << " is a directory\n";
    if(fs::is_block_file(stat))
		std::cout << path << " is a block device\n";
    if(fs::is_character_file(stat))
		std::cout << path << " is a character device\n";
    if(fs::is_fifo(stat))
		std::cout << path << " is a named IPC pipe\n";
    if(fs::is_socket(stat))
		std::cout << path << " is a named IPC socket\n";
    if(fs::is_symlink(stat))
		std::cout << path << " is a symlink\n";
}
 
int main()
{
	// Create a file to work with
	std::string filename{"test.txt"};
	std::ofstream test(filename); // create file
	test.close();
	
	show_status(filename);
	show_status(".");
	show_status("test2.txt");
	
	// Delete our work file
	fs::remove("test.txt");
}