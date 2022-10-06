#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
 
// A convenient namespace alias
namespace fs = std::filesystem;
 
// A convenient type alias
using fsp = std::filesystem::perms;

void show_status(const fs::directory_entry& de)
{
	// Get the directory's file status
	fs::file_status stat = fs::status(de);
	
	// Does this file exist?
	if(!fs::exists(stat)) {
		std::cout << de << " does not exist\n";
		return;
	}
	
	// Get some information about the file
    if(fs::is_regular_file(stat))
		std::cout << de << " is a regular file\n";
    if(fs::is_directory(stat))
		std::cout << de << " is a directory\n";
    if(fs::is_symlink(de))
		std::cout << de << " is a symlink\n";
}

void show_permissions(const fs::directory_entry& de)
{
	// Get the file's status
	fs::file_status stat = fs::status(de);
	
	// Get the file's permissions
	auto perm = stat.permissions();
	
	// Get some information about the file's permissions
    std::cout << ((perm & fsp::owner_read) != fsp::none ? "r" : "-")
              << ((perm & fsp::owner_write) != fsp::none ? "w" : "-")
              << ((perm & fsp::owner_exec) != fsp::none ? "x" : "-")
              << ((perm & fsp::group_read) != fsp::none ? "r" : "-")
              << ((perm & fsp::group_write) != fsp::none ? "w" : "-")
              << ((perm & fsp::group_exec) != fsp::none ? "x" : "-")
              << ((perm & fsp::others_read) != fsp::none ? "r" : "-")
              << ((perm & fsp::others_write) != fsp::none ? "w" : "-")
              << ((perm & fsp::others_exec) != fsp::none ? "x" : "-")
              << '\n';
}

int main() {
	fs::path temp{"temp"};
	fs::create_directory(temp);
	std::ofstream tempfile("temp/test.txt");
	
	fs::create_directories("temp/dir1/dir2/dir3");
	
	fs::recursive_directory_iterator dir{temp};
	
	for (const auto& entry: dir) {
        // Display some data about the directory entry
        std::cout << '\n' << entry << '\n';
		show_status(entry);
		show_permissions(entry);
	}
	
	tempfile.close();
	fs::remove_all(temp);
}