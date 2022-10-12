#include <algorithm>
#include <vector>
#include <exception>
#include <iostream>

int main()
{
	std::vector<int> vec{3,1,4,1,5,9};
	
	try {
		std::sort(begin(vec), end(vec),
                  [](int a, int b) {
			           throw std::out_of_range("Oops"); return true;});
	}
	catch (std::exception& e) {
		std::cout << "Caught exception: " << e.what() << "\n";
	}
}