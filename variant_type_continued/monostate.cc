#include <variant>

struct NonDefault {
	int i{0};
	NonDefault(int i): i(i) {}
};

int main()
{
	//std::variant<NonDefault> var;                    // Error!

	// Solution: put std::monostate as the first alternative
	std::variant<std::monostate, NonDefault> var;      // OK
}
