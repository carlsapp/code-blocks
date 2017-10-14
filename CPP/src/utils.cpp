#include <iostream>  // For cout and endl

void printArray(int arrayToPrint[], unsigned int arrayLen)
{
    for (unsigned int i = 0; i < arrayLen; i++) {
        std::cout << arrayToPrint[i] << " ";
    }
    std::cout << std::endl;
}

bool sortIsValid(int origArray[], int sortedArray[], unsigned int arrayLen)
{
		int origSum = origArray[0], sortSum = sortedArray[0];
		for (unsigned int i = 1; i < arrayLen; i++) {
        origSum += origArray[i];
        sortSum += sortedArray[i];
        if (sortedArray[i - 1] > sortedArray[i]) {
        		return false;
        }
    }
    if (origSum != sortSum) {
    		return false;
    }
    return true;
}
