#include <iostream>  // For cout and endl
#include "mergeSort.h"
#include "quickSort.h"
#include "utils.h"  // For printArray()

int main()
{
    std::cout << "Hello World" << std::endl;
    int intVariable = 8;
    int *intPointer = &intVariable;
    std::cout << "Value of intVariable: " << intVariable << std::endl;
    std::cout << "Address of intVariable: " << &intVariable << std::endl;
    std::cout << "Value of intPointer: " << intPointer << std::endl;
    std::cout << "Value of *intPointer: " << *intPointer << std::endl;
    
    int arrayToSort[] = {3, 4, 2, 0, 1};
    mergeSortInt(arrayToSort, 5);
    printArray(arrayToSort, sizeof(arrayToSort) / sizeof(arrayToSort[0]));
    int arrayToSort2[] = {8, 3, 10, 22, 98, 1};
    mergeSortInt(arrayToSort2, 6);
    printArray(arrayToSort2, sizeof(arrayToSort2) / sizeof(arrayToSort2[0]));
    int arrayToSort3[] = {8, 3};
    mergeSortInt(arrayToSort3, 2);
    printArray(arrayToSort3, sizeof(arrayToSort3) / sizeof(arrayToSort3[0]));
    int arrayToSort4[] = {3, 8};
    mergeSortInt(arrayToSort4, 2);
    printArray(arrayToSort4, sizeof(arrayToSort4) / sizeof(arrayToSort4[0]));
    int arrayToSort5[] = {3};
    mergeSortInt(arrayToSort5, 1);
    printArray(arrayToSort5, sizeof(arrayToSort5) / sizeof(arrayToSort5[0]));
    
    int arrayToSort6[] = {3, 4, 2, 0, 1};
    quickSortInt(arrayToSort6, 5, 0.5);
    printArray(arrayToSort6, 5);
    
}