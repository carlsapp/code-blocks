#include <iostream>  // For cout and endl
#include <cstdlib>
#include <ctime>
#include "mergeSort.h"
#include "quickSort.h"
#include "utils.h"  // For printArray()

int main()
{
    /*std::cout << "Hello World" << std::endl;
    int intVariable = 8;
    int *intPointer = &intVariable;
    std::cout << "Value of intVariable: " << intVariable << std::endl;
    std::cout << "Address of intVariable: " << &intVariable << std::endl;
    std::cout << "Value of intPointer: " << intPointer << std::endl;
    std::cout << "Value of *intPointer: " << *intPointer << std::endl;
    std::cout << std::endl;*/
    
    unsigned int seed = std::time(0);
    unsigned int loops = 5;
    //unsigned int minArraySize = 20000;
    unsigned int maxArraySize = 100000;
    unsigned int maxValue = 10;
    
    std::cout << "Sorting Algorithms" << std::endl << std::endl;
    std::cout << "Test Params - Seed: " << seed << ", Loops: " << loops;
    std::cout << ", Max Array Size: " << maxArraySize << " Max Value: " << maxValue << std::endl;
    
		int myArray[5] = {2, 7, 5, 3, 1};
		mergeSort(myArray, 5);
		printArray(myArray, 5);
    
/*    std::srand(seed);  // Seed the random number generator
    int startTime, computeTime;
    
    for (unsigned int loopNum = 0; loopNum < loops; loopNum++) {
        unsigned int arraySize = (std::rand() % (maxArraySize - minArraySize)) + minArraySize;
        int *unsortedArray = new int[arraySize];
        int *arrayToSort = new int[arraySize];
        for (unsigned int i = 0; i < arraySize; i++) {
        		unsortedArray[i] = std::rand() % maxValue;
        }
        std::cout << "Unsorted Array: ";
        printArray(unsortedArray, arraySize);
        
        memcpy(arrayToSort, unsortedArray, arraySize * sizeof(int));
        startTime = std::clock();
        mergeSortInt(arrayToSort, arraySize);
        computeTime = std::clock() - startTime;
        std::cout << "MergeSort (" << computeTime << " ticks): ";
        printArray(arrayToSort, arraySize);
        if (!sortIsValid(unsortedArray, arrayToSort, arraySize)) {
        		std::cout << std::endl << "ERROR: Array is not sorted correctly!" << std::endl << std::endl;
        }
        
        memcpy(arrayToSort, unsortedArray, arraySize * sizeof(int));
        startTime = std::clock();
        quickSortInt(arrayToSort, arraySize);
        computeTime = std::clock() - startTime;
        std::cout << "QuickSort End Pivot (" << computeTime << " ticks): ";
        printArray(arrayToSort, arraySize);
        if (!sortIsValid(unsortedArray, arrayToSort, arraySize)) {
        		std::cout << std::endl << "ERROR: Array is not sorted correctly!" << std::endl << std::endl;
        }
        
        memcpy(arrayToSort, unsortedArray, arraySize * sizeof(int));
        startTime = std::clock();
        quickSortInt(arrayToSort, arraySize, 0.5);
        computeTime = std::clock() - startTime;
        std::cout << "QuickSort Mid Pivot (" << computeTime << " ticks): ";
        printArray(arrayToSort, arraySize);
        if (!sortIsValid(unsortedArray, arrayToSort, arraySize)) {
        		std::cout << std::endl << "ERROR: Array is not sorted correctly!" << std::endl << std::endl;
        }
        
        delete[] unsortedArray;
        delete[] arrayToSort;
    }*/
    /*int random_variable = std::rand();
    
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
    printArray(arrayToSort6, 5);*/
    
}
