#include <iostream>


int main()
{
    int value = 4;
    
    // Assigning a pointer during initialization
    int * pointer = &value;
    
    // Assigning a pointer after initialization
    int * pointer2;
    pointer2 = &value;
    
    // Assigning a pointer to point to a specific address
    // Note that this address is a random address
    int * pointer3 = (int *) 0x7fff52b4aa4c;
    
    std::cout << "Address of value: " << &value << std::endl;
    std::cout << "*pointer: " << *pointer << std::endl;
    std::cout << "*pointer2: " << *pointer2 << std::endl;
    
    std::cout << "Changing value ..." << std::endl;
    value = 5;
    
    std::cout << "*pointer: " << *pointer << std::endl;
    std::cout << "*pointer2: " << *pointer2 << std::endl;
    std::cout << "pointer2: " << pointer2 << std::endl;
    std::cout << "pointer3: " << pointer3 << std::endl;
}
