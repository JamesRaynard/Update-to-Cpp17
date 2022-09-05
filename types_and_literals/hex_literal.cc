#include <iostream>

int main()
{
	int i = 0x2a;
	std::cout << "i: " << i << "\n";
	
	// Is f a hexadecimal digit or a type suffix?
	// auto ambig = 0x2.f;                         // Error: hex floating constants require an exponent

	double d = 0xA.8p2;
	std::cout << "d: " << d << "\n";
	
	float f = 0xC.7Fp3;
	std::cout << "f: " << f << "\n";
}