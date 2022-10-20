#include <vector>
#include <type_traits>

// Vector-like class with elements of type T
template <typename T>
class new_vector {
  public:
	// Constructor takes a range of iterators which have type Iter
    template <typename Iter> new_vector(Iter, Iter) {}
};

// Deduction guide
// The constructor will "return" a new_vector object
// The new_vector's type parameter will be the type that Iter points to
template <typename Iter>
new_vector(Iter, Iter) -> new_vector<typename std::iterator_traits<Iter>::value_type>;

int main()
{
	std::vector vec{1, 2, 3};
	
	// Equivalent to new_vector<int> vec2{begin(vec), end(vec)}
	new_vector vec2{begin(vec), end(vec)};
	
	//static_assert(std::is_same_v<decltype(vec2), new_vector<int>>);
}