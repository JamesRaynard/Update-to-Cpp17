#ifndef FUNCTION_H
#define FUNCTION_H

// Free function defined in header
// inline
void func() {}

// Member function defined in header
class Test {
public:
	void func() {}
};

// constexpr function defined in header
constexpr int meaning_of_life() { return 42; }

#endif // FUNCTION_H
