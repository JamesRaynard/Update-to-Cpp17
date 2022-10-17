#include <iostream>
#include <string>
#include <tuple>

using namespace std::literals;

// Our custom type
struct Test {
	int i;
	double d;
	std::string s;
};

// Implement get<idx> for our type
template<int Idx>
auto get(const Test& test)            // Function returning "auto"
{
   if constexpr (Idx == 0)            // Return the value which corresponds to the index
       return test.i;   
   else if constexpr (Idx == 1)
       return test.d;
	else if constexpr (Idx == 2)
       return test.s;
}

namespace std {
     // tuple_element will be replaced by the type of the element
     template<> struct tuple_element<0, Test> { using type = int; };
     template<> struct tuple_element<1, Test> { using type = double; };
     template<> struct tuple_element<2, Test> { using type = std::string; };
   
     // tuple_size will be replaced by the number of elements
     template<> struct tuple_size<Test>: public integral_constant<size_t, 3> {};
}

// Function which returns the last member of a Test object
template<typename Test>
constexpr auto get_last(const Test& test)
{
	// Find the number of elements
	constexpr auto size = std::tuple_size<Test>::value;
	
	// Check there is at least one element
	static_assert(size > 0);
	
	// Return it
	return get<size-1>(test);
}

int main()
{	
	Test test{1, 2.0, "three"s};
	std::cout << "Last element of Test object is: ";
	std::cout << get_last(test) << '\n';
}