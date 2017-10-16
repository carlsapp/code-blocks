#include <iostream>


long long addr_of_stack_in_func() {
    int var3 = 6;
    std::cout << "Address of variable in a function we just called: " << &var3 << std::endl;
    // We convert it to a long long to get past a compiler warning
    return (long long)&var3;
}


int main()
{
    int var1 = 4;
    int var2 = 5;
    std::cout << "Address of 1st variable: " << &var1 << std::endl;
    std::cout << "Address of 2nd variable: " << &var2 << std::endl;
    
    // Check how the compiler arranges var1 and var2 in the address map
    if (&var2 > &var1) {
        std::cout << "The compiler grows the stack downward (adds addresses)" << std::endl;
        std::cout << "Size of int: " << ((long long)&var2 - (long long)&var1) << std::endl;
    } else {
        std::cout << "The compiler grows the stack upward (subtracts addresses)" << std::endl;
        std::cout << "Size of int: " << ((long long)&var1 - (long long)&var2) << std::endl;
    }
    
    // Check how the architecture adjusts the stack with the CALL instruction
    if (addr_of_stack_in_func() > (long long)&var1) {
        std::cout << "The architecture grows the stack downward (adds addresses)" << std::endl;
    } else {
        std::cout << "The architecture grows the stack upward (subtracts addresses)" << std::endl;
    }
    
}
