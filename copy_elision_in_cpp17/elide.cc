#include <iostream>

class Test {
  public:
	Test() { std::cout << "Default constructor\n"; }
    
	// Copy constructor with side effect
	Test(const Test& other) { std::cout << "Copying\n"; }
};

// Function returning a temporary object
Test func()
{
    return Test{};
}

int main()
{
	std::cout << "Calling func()\n";
	
	// How many times is "Copying" printed out?
	Test test = func();
	
	std::cout << "Returned from func()\n";
}
