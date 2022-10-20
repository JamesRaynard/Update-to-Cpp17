#include <iostream>
#include <type_traits>

// C++14 alias for type traits
// enable_if_t<...>
// Is equivalent to typename enable_if<...>::type
template<typename T,
	std::enable_if_t<std::is_same<T, int>::value, int> = 42>
	void func(const T& t)
{
	std::cout << t << '\n';
}

int main()
{
	func(99);
}