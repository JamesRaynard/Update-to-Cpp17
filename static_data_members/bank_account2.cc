#include <iostream>
#include "bank_account.h"

int main()
{
	// Use the static data member
	std::cout << "Interest rate: "
		      << bank_account::interest_rate << "\n";
}