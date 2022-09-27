#include <iostream>
#include <chrono>

// A convenient alias
namespace sc = std::chrono;

using namespace std::literals;  // For suffixes

int main()
{
	//seconds s = 5043ms;                           // Error - data would be lost
	
	sc::seconds s = sc::duration_cast<sc::seconds>(5043ms);     // OK - but s is truncated to 5 seconds
	std::cout << "5043ms converted to " << s.count() << " seconds\n";
	
	sc::seconds s2 = sc::duration_cast<sc::seconds>(-5043ms);     // OK - but s2 is truncated to -5 seconds
	std::cout << "-5043ms converted to " << s2.count() << " seconds\n";
}