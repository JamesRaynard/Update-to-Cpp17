int main()
{
	int i{1};
	constexpr int n{4};
	
	[n, &i] ()  {                   // i is not a constant expression
		++i;
		if constexpr (n % 2 == 1)
			return true;
		return false;
	};
}