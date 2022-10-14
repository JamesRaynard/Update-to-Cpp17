#include <execution>
#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>

// A convenient alias
namespace se = std::execution;

int main() {
	std::vector expected{ 0.1, 0.2, 0.3, 0.4, 0.5 };
	std::vector actual{ 0.09, 0.22, 0.27, 0.41, 0.52 };
	
	auto max_diff = std::transform_reduce(se::par_unseq,
                                          begin(expected), end(expected), begin(actual),
                                          0.0,
										  // Reduce operation
                                          [](auto a, auto b){ return std::max(a,b); },
										  // Transform operation 
                                          [](auto l, auto r) { return fabs(r-l); }); 

	std::cout << "Max difference is: " << max_diff << '\n';
}