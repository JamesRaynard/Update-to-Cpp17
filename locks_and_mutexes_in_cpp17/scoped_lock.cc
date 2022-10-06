#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <vector>

std::mutex task_mutex, str_mutex;                     // Global mutex objects
std::string str;                                      // Shared memory location

void task(int arg)
{
	for (int i = 0; i < 5; ++i) {
		std::scoped_lock sl(str_mutex, task_mutex);   // Use a scoped_lock to lock the critical region
		//std::scoped_lock sl;                        // Lock object, but not bound to any mutex
		if (arg == 1)
			str = "abc";
		else if (arg == 2)
			str = "def";
		else if (arg == 3)
			str = "xyz";

		std::cout << str[0] << str[1] << str[2] << std::endl;
	} // The lock is released when the scoped_lock object goes out of scope
}

int main()
{
	std::vector<std::thread> tasks;
	
	for (int i = 0; i < 5; ++i) {
		tasks.push_back(std::thread{task, 1});
		tasks.push_back(std::thread{task, 2});
		tasks.push_back(std::thread{task, 3});
	}

	for (auto& t: tasks) t.join();
}