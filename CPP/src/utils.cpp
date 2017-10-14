#include <iostream>  // For cout and endl

void printArray(int arrayToPrint[], unsigned int arrayLen)
{
    for (unsigned int i = 0; i < arrayLen; i++) {
        std::cout << arrayToPrint[i] << " ";
    }
    std::cout << std::endl;
}