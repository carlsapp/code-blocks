#include <cstring>

void mergeSortInt(int intArray[], int arrayLen)
{
    if (arrayLen < 2) {
        return;
    }
    int midIndex = arrayLen / 2;
    // Sort the first half
    mergeSortInt(intArray, midIndex);
    // Sort the second half
    mergeSortInt(intArray + midIndex, arrayLen - midIndex);
    
    // And merge the two sorted halves
    // Copy our data to a temporary array. We will be putting the result into the original array.
    int *intArrayCopy = new int[arrayLen];
    memcpy(intArrayCopy, intArray, arrayLen * sizeof(int));
    int firstHalfPos = 0, destPos = 0;
    int secondHalfPos = midIndex;
    while (firstHalfPos < midIndex && secondHalfPos < arrayLen) {
        if (intArrayCopy[firstHalfPos] <= intArrayCopy[secondHalfPos]) {
            intArray[destPos++] = intArrayCopy[firstHalfPos++];
        } else {
            intArray[destPos++] = intArrayCopy[secondHalfPos++];
        }
    }
    // Copy anything still left
    while (firstHalfPos < midIndex) {
        intArray[destPos++] = intArrayCopy[firstHalfPos++];
    }
    while (secondHalfPos < arrayLen) {
        intArray[destPos++] = intArrayCopy[secondHalfPos++];
    }
    delete[] intArrayCopy;
}

template<typename T>
void mergeSort(T intArray[], int arrayLen)
{
    if (arrayLen < 2) {
        return;
    }
    int midIndex = arrayLen / 2;
    // Sort the first half
    mergeSortInt(intArray, midIndex);
    // Sort the second half
    mergeSortInt(intArray + midIndex, arrayLen - midIndex);
    
    // And merge the two sorted halves
    // Copy our data to a temporary array. We will be putting the result into the original array.
    T *intArrayCopy = new int[arrayLen];
    memcpy(intArrayCopy, intArray, arrayLen * sizeof(T));
    int firstHalfPos = 0, destPos = 0;
    int secondHalfPos = midIndex;
    while (firstHalfPos < midIndex && secondHalfPos < arrayLen) {
        if (intArrayCopy[firstHalfPos] <= intArrayCopy[secondHalfPos]) {
            intArray[destPos++] = intArrayCopy[firstHalfPos++];
        } else {
            intArray[destPos++] = intArrayCopy[secondHalfPos++];
        }
    }
    // Copy anything still left
    while (firstHalfPos < midIndex) {
        intArray[destPos++] = intArrayCopy[firstHalfPos++];
    }
    while (secondHalfPos < arrayLen) {
        intArray[destPos++] = intArrayCopy[secondHalfPos++];
    }
    delete[] intArrayCopy;
}