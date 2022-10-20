#include <iostream>
#include <type_traits>

// C++11 - enable_if without template aliases
template<typename T,
	typename std::enable_if<std::is_same<T, int>::value, int>::type = 42>
	void func(const T& t)
{
	std::cout << t << '\n';
}

int main()
{
	func(99);
}