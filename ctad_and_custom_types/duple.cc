#include <type_traits>

template <typename A, typename B>
class duple {
  public:
    duple() {}
    duple(const A& a, const B& b) : a(a), b(b) {}
  private:
	A a;
	B b;
};

int main()
{
    // Equivalent to duple<int, int> mp{42, 99};
	duple mp{42, 99};
    
	// Check that they really are the same
	//static_assert(std::is_same_v<decltype(mp), duple<int, int>>);
	
	// Equivalent to duple<???, ???> mp{};
	//duple mp2;                // Error - cannot deduce the class parameters
	
	duple<long, float> mp3{};   // OK - the class parameters are explicit
}