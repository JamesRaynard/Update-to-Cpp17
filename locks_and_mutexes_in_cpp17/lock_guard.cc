#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <vector>

std::mutex task_mutex;						// Global mutex object

void task(std::string str)
{
    for (int i = 0; i < 5; ++i) {
		//std::lock_guard<std::mutex> lg(task_mutex);		// Use a lock_guard to lock the critical region
        std::cout << str[0] << str[1] << str[2] << '\n';
    } // The lock is released when the lock_guard object goes out of scope
}

int main()
{
	std::vector<std::thread> tasks;

	for (int i = 0; i < 5; ++i) {
		tasks.push_back(std::thread{task, "abc"});
		tasks.push_back(std::thread{task, "def"});
		tasks.push_back(std::thread{task, "ghi"});
	}

	for (auto& t: tasks) t.join();
}