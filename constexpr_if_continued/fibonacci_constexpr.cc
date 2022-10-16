#include <iostream>

template<int N>
constexpr int fibonacci()
{
	if constexpr (N > 1)
		return fibonacci<N-1>() + fibonacci<N-2>();
	return N;
}

int main()
{
	constexpr int n{10};
	std::cout << "The " << n << "th Fibonacci number is: " << fibonacci<n>() << '\n';
}