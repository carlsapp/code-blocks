#include <thread>
#include <mutex>
#include <iostream>

std::mutex print_coordination_mutex;
 
void coordinated_print(unsigned int num_prints, int value_to_print)
{
    // The lock_guard is locked in initialization and unlocked at destruction
    std::lock_guard<std::mutex> lock(print_coordination_mutex);
    
    for (unsigned int i = 0; i < num_prints; i++) {
        std::cout << value_to_print;
        std::this_thread::yield();
    }
}

void overlapping_print(unsigned int num_prints, int value_to_print)
{
    for (unsigned int i = 0; i < num_prints; i++) {
        std::cout << value_to_print;
        // If we don't include the yield, the OS will allow us to print all of our prints
        // before moving over to the other thread.
        std::this_thread::yield();
    }
}

int main()
{
    std::cout << "The threads should overlap in prints here: " << std::endl;
    std::thread t1(overlapping_print, 100, 0);
    std::thread t2(overlapping_print, 100, 1);

    // Wait for the threads to complete
    t1.join();
    t2.join();
    
    std::cout << std::endl << std::endl;
    std::cout << "The threads should NOT overlap in prints here: " << std::endl;
    std::thread t3(coordinated_print, 100, 0);
    std::thread t4(coordinated_print, 100, 1);
    t3.join();
    t4.join();
    std::cout << std::endl;
}
