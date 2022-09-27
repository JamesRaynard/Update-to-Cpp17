#include <iostream>
#include <chrono>

// A convenient alias
namespace sc = std::chrono;

using namespace std::literals;

int main()
{
	{
		std::cout << "Using std::ceil()\n";
		sc::seconds s = sc::ceil<sc::seconds>(5043ms);     // s is rounded to 6 seconds
		std::cout << "5043ms converted to " << s.count() << " seconds\n";
		
		sc::seconds s2 = sc::ceil<sc::seconds>(-5043ms);     // s2 is rounded to -5 seconds
		std::cout << "-5043ms converted to " << s2.count() << " seconds\n\n";
	}
	
	{
		std::cout << "Using std::floor()\n";
		sc::seconds s = sc::floor<sc::seconds>(5043ms);     // s is rounded to 5 seconds
		std::cout << "5043ms converted to " << s.count() << " seconds\n";
		
		sc::seconds s2 = sc::floor<sc::seconds>(-5043ms);     // s2 is rounded to -6 seconds
		std::cout << "-5043ms converted to " << s2.count() << " seconds\n\n";
	}
	{
		std::cout << "Using std::round()\n";
		sc::seconds s = sc::round<sc::seconds>(5043ms);     // s is rounded to 5 seconds
		std::cout << "5043ms converted to " << s.count() << " seconds\n";
		
		sc::seconds s2 = sc::round<sc::seconds>(-5043ms);     // s2 is rounded to -5 seconds
		std::cout << "-5043ms converted to " << s2.count() << " seconds\n";
		
		sc::seconds s3 = sc::round<sc::seconds>(5500ms);     // s3 is rounded to 6 seconds
		std::cout << "5500ms converted to " << s3.count() << " seconds\n";
		
		sc::seconds s4 = sc::round<sc::seconds>(4500ms);     // s4 is rounded to 4 seconds
		std::cout << "4500ms converted to " << s4.count() << " seconds\n";
	}
}