#include <iostream>
#include <vector>

class refrigerator {
	// Data members
	int temperature;
	bool door_open;
	bool power_on;
public:
	refrigerator(int temp, bool open, bool power): temperature(temp), door_open(open), power_on(power) {}
	void print()
	{
		std::cout << "Temperature = " << temperature;
		std::cout << std::boolalpha;
		std::cout << ", door_open = " << door_open;
		std::cout << ", power_on = " << power_on;
	}
};

int main()
{
	std::vector<refrigerator> vec;

	refrigerator fridge(2, false, true);                  // Create a refrigerator object
	vec.insert(vec.begin(), fridge);                      // Add an element and copy fridge into it

	std::cout << "Vector elements:\n";
	for (auto el : vec) {
		el.print();
		std::cout << "\n";
	}
	
	auto back = vec.emplace_back(3, false, true);    // Create new element at back
	std::cout << "\nEmplaced an element at the back of the vector: \n";
	back.print();                                                  // Print out the new element

	std::cout << "\n\nVector elements:\n";
	for (auto el : vec) {
		el.print();
		std::cout << "\n";
	}
}
