int func(int x) 
{
#ifdef USE_X
	return x;
#else
	return 99;
#endif
}

int main() 
{
	func(42);
}