#include <iostream>
#include <filesystem>

// A convenient namespace alias
namespace fs = std::filesystem;

// Display num in Gigabytes (to 3 decimal places)
void to_gb(uintmax_t num) {
	auto exp = num/1'000'000'000;
	auto rem = num - exp*1'000'000'000;
	rem /= 1'000'000;
	std::cout << exp << "." << rem << "G";
}

int main() {
	fs::space_info si = fs::space("C:");
	
	std::cout << "C drive:\n";
	std::cout << "Capacity: "; 
	to_gb(si.capacity);
	std::cout << "\nFree: ";
	to_gb(si.free);
	std::cout << "\nAvailable: ";
	to_gb(si.available);
	std::cout << '\n';
}