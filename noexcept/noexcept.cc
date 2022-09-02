#include <iostream>

/*
void func()
{
	// Could throw an exception in here
}
*/

void func() noexcept
{
	// Should not throw an exception in here
}


int main() 
{
    auto f = func;
    std::cout << std::boolalpha << noexcept(f()) << '\n';
}