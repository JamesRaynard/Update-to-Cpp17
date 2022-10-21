#include <iostream>

template<auto func>
class FunctionWrapper {
public:
    template<typename... Args>
    auto operator()(Args &&... args) const
	{
        return func(std::forward<Args>(args)...);
    }
};

int add(int a, int b)
{
    return a + b;
}

int main()
{
    FunctionWrapper<add> wrapper;
    std::cout << "FunctionWrapper<add>(1, 2) returns " << wrapper(1, 2) << '\n';
}
