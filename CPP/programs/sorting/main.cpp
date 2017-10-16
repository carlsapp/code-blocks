#include <iostream>  // For cout and endl
#include <ctime>
#include "merge_sort.h"
#include "quick_sort.h"
#include "insertion_sort.h"
#include "bubble_sort.h"
#include "utils.h"  // For printArray()

int main()
{   
    unsigned int seed = std::time(0);
    unsigned int loops = 1;
    unsigned int minArraySize = 5;
    unsigned int maxArraySize = 10;
    unsigned int maxValue = 10;
    
    std::cout << "Sorting Algorithms" << std::endl << std::endl;
    std::cout << "Test Params - Seed: " << seed << ", Loops: " << loops;
    std::cout << ", Array Size: " << minArraySize << " - " << maxArraySize;
    std::cout << ", Max Value: " << maxValue << std::endl << std::endl;
    
    std::srand(seed);  // Seed the random number generator
    int startTime, computeTime;
    
    for (unsigned int loopNum = 0; loopNum < loops; loopNum++) {
        unsigned int arraySize = (std::rand() % (maxArraySize - minArraySize)) + minArraySize;
        int *unsortedArray = new int[arraySize];
        int *arrayToSort = new int[arraySize];
        for (unsigned int i = 0; i < arraySize; i++) {
            unsortedArray[i] = std::rand() % maxValue;
        }
        
        if (loops <= 5) {
            std::cout << "Loop " << loopNum << " - Array Size " << arraySize << std::endl;
        }
        if (arraySize < 50) {
            std::cout << "Unsorted Array: ";
            printArray(unsortedArray, arraySize);
        }
        
        // Merge Sort
        memcpy(arrayToSort, unsortedArray, arraySize * sizeof(int));
        startTime = std::clock();
        mergeSort(arrayToSort, arraySize);
        //arrayToSort[arraySize - 3] = 0;
        computeTime = std::clock() - startTime;
        if (loops <= 5) {
            std::cout << "Merge Sort (" << computeTime << " ticks)";
            if (arraySize < 50) {
                std::cout << ": ";
                printArray(arrayToSort, arraySize);
            } else {
                std::cout << std::endl;
            }
        }
        if (!sortIsValid(unsortedArray, arrayToSort, arraySize)) {
            std::cout << std::endl << "ERROR: Array is not sorted correctly!" << std::endl << std::endl;
        }
        
        // Quick Sort End Pivot
        memcpy(arrayToSort, unsortedArray, arraySize * sizeof(int));
        startTime = std::clock();
        quickSortEndPivot(arrayToSort, arraySize);
        computeTime = std::clock() - startTime;
        if (loops <= 5) {
            std::cout << "Quick Sort End Pivot (" << computeTime << " ticks)";
            if (arraySize < 50) {
                std::cout << ": ";
                printArray(arrayToSort, arraySize);
            } else {
                std::cout << std::endl;
            }
        }
        if (!sortIsValid(unsortedArray, arrayToSort, arraySize)) {
            std::cout << std::endl << "ERROR: Array is not sorted correctly!" << std::endl << std::endl;
        }
        
        // Quick Sort Mid Pivot
        memcpy(arrayToSort, unsortedArray, arraySize * sizeof(int));
        startTime = std::clock();
        quickSort(arrayToSort, arraySize, 0.5);
        computeTime = std::clock() - startTime;
        if (loops <= 5) {
            std::cout << "Quick Sort Mid Pivot (" << computeTime << " ticks)";
            if (arraySize < 50) {
                std::cout << ": ";
                printArray(arrayToSort, arraySize);
            } else {
                std::cout << std::endl;
            }
        }
        if (!sortIsValid(unsortedArray, arrayToSort, arraySize)) {
            std::cout << std::endl << "ERROR: Array is not sorted correctly!" << std::endl << std::endl;
        }
        
        // Insertion Sort
        memcpy(arrayToSort, unsortedArray, arraySize * sizeof(int));
        startTime = std::clock();
        insertionSort(arrayToSort, arraySize);
        computeTime = std::clock() - startTime;
        if (loops <= 5) {
            std::cout << "Insertion Sort (" << computeTime << " ticks)";
            if (arraySize < 50) {
                std::cout << ": ";
                printArray(arrayToSort, arraySize);
            } else {
                std::cout << std::endl;
            }
        }
        if (!sortIsValid(unsortedArray, arrayToSort, arraySize)) {
            std::cout << std::endl << "ERROR: Array is not sorted correctly!" << std::endl << std::endl;
        }
        
        // Bubble Sort
        memcpy(arrayToSort, unsortedArray, arraySize * sizeof(int));
        startTime = std::clock();
        bubbleSort(arrayToSort, arraySize);
        computeTime = std::clock() - startTime;
        if (loops <= 5) {
            std::cout << "Bubble Sort (" << computeTime << " ticks)";
            if (arraySize < 50) {
                std::cout << ": ";
                printArray(arrayToSort, arraySize);
            } else {
                std::cout << std::endl;
            }
        }
        if (!sortIsValid(unsortedArray, arrayToSort, arraySize)) {
            std::cout << std::endl << "ERROR: Array is not sorted correctly!" << std::endl << std::endl;
        }
        
        if (loops <= 5) {
            std::cout << std::endl;
        }
        
        delete[] unsortedArray;
        delete[] arrayToSort;
    }
    
}
