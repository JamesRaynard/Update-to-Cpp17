#include <iostream>

class Test {
	int time{10};                       // Data member
public:
	void countdown()                    // Member function
	{
		// Lambda expression
		[this] ()                       // Capture this object by reference
		{
			if (time > 0)
				std::cout << time << '\n';
			else if (time == 0)
				std::cout << "Liftoff!" << '\n';
			--time;
		}();                            // Call the lambda expression
	}
};

int main()
{
	Test test;
	for (int i = 0; i < 12; ++i)
		test.countdown();
}