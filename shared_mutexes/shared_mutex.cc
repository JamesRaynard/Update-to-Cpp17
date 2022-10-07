#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <chrono>
#include <vector>

using namespace std::literals;

// The shared mutex object
std::shared_mutex shmut;

// Mutex to protect std::cout
std::mutex print_mutex;

void write(int i)
{
    {
        // Use print_mutex to protect std::cout
        std::scoped_lock<std::mutex> pg(print_mutex);
        std::cout << "Writer thread " << i << " trying to lock" << '\n';
    }

    // Get an exclusive lock on the shared mutex
    std::scoped_lock<std::shared_mutex> lg(shmut);

    {
        // Use print_mutex to protect std::cout
        std::scoped_lock<std::mutex> pg(print_mutex);
        std::cout << "Writer thread " << i << " has exclusive lock" << '\n';
    }
    std::this_thread::sleep_for(2s);
}

void read(int i)
{
    {
        // Use print_mutex to protect std::cout
        std::scoped_lock<std::mutex> pg(print_mutex);
        std::cout << "Reader thread " << i << " trying to lock" << '\n';
    }

    // Get a shared lock on the shared mutex
    std::shared_lock<std::shared_mutex> sl(shmut);

    {
        // Use print_mutex to protect std::cout
        std::scoped_lock<std::mutex> pg(print_mutex);
        std::cout << "Reader thread " << i << " has shared lock" << '\n';
    }
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