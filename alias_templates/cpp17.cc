#include <iostream>
#include <type_traits>

// C++17 alias for type traits
// std::is_same_v<...>
// Is equivalent to std::is_same<...>::value
template<typename T, std::enable_if_t<
                 std::is_same_v<T,int>, int> = 42>
void func(const T& t)
{
	std::cout << t << '\n';
}

int main()
{
	func(99);
}