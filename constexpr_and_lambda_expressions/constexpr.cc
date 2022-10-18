int main()
{
	constexpr auto is_odd = [] (int n) constexpr {
		return (n % 2 == 1); 
	};
	
	static_assert(is_odd(4) == false);
}