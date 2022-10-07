#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>

using namespace std::literals;

std::mutex the_mutex;

// Mutex to protect std::cout
std::mutex print_mutex;

void write(int i) {
	{
		// Use print_mutex to protect std::cout
		std::scoped_lock<std::mutex> pg(print_mutex);
		std::cout << "Writer thread " << i << " trying to lock" << '\n';
	}

	std::scoped_lock<std::mutex> lg(the_mutex);
	
	{
		// Use print_mutex to protect std::cout
		std::scoped_lock<std::mutex> pg(print_mutex);
		std::cout << "Writer thread " << i << " has exclusive lock" << '\n';
	}

	std::this_thread::sleep_for(2s);
}

void read(int i) {
	{
		// Use print_mutex to protect std::cout
		std::scoped_lock<std::mutex> pg(print_mutex);
		std::cout << "Reader thread " << i << " trying to lock" << '\n';
	}

	std::scoped_lock<std::mutex> sl(the_mutex);

	{
		// Use print_mutex to protect std::cout
		std::scoped_lock<std::mutex> pg(print_mutex);
		std::cout << "Reader thread " << i << " has exclusive lock" << '\n';
	}

	std::this_thread::sleep_for(2ms);
}

int main() {
	std::vector<std::thread> threads;

	for (int i = 0; i < 50; ++i)
		threads.push_back(std::thread{read, i});

	threads.push_back(std::thread{write, 51});
	threads.push_back(std::thread{write, 52});

	for (int i = 0; i < 100; ++i)
		threads.push_back(std::thread{read, i+52});

	for (auto& t : threads)
		t.join();
}