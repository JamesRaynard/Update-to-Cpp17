#include <iostream>
#include <tuple>
#include <string>

using namespace std::literals;

struct Test {
	int i;
	double d;
	std::string s;
	Test(int i, double d, std::string s) : i(i), d(d), s(s) {}
	void print() {
		std::cout << "i = " << i << ", d = " << d << ", s = " << s << '\n';
	}
};

int main()
{
	// Calls Test(1, 2.0, "three"s);
	auto test = std::make_from_tuple<Test>(std::tuple(1, 2.0, "three"s));
	test.print();
}