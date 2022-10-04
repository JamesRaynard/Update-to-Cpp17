#include <bitset>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

// A convenient namespace alias
namespace fs = std::filesystem;

// Convenient type aliases
using fsp = std::filesystem::perms;
using fspo = std::filesystem::perm_options;
 
void show_permissions(const fs::path& pth)
{
	// Get the file's status
	fs::file_status stat = fs::status(pth);
	
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

int main()
{
	// Create a file to work with
    std::string filename{"test.txt"};
	std::ofstream test(filename); // create file
 
    std::cout << "Created " << filename << " with permissions: ";
	test.close();
	
    show_permissions(filename);
 
    fs::permissions("test.txt", fsp::owner_write, fspo::remove);

    std::cout << "After removing u-w:  ";
    show_permissions(filename);
 
	fs::permissions("test.txt",
                       fsp::owner_all | fsp::group_all,
                       fspo::add);

    std::cout << "After adding u+rwx and g+rwx:  ";
	show_permissions(filename);
    
	// Delete our work file
	remove("test.txt");
}