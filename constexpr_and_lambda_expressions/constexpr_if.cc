int main()
{
	constexpr int n{4};
	[n] ()  {
		if constexpr (n % 2 == 1)
			return true;
		return false;
	};
}