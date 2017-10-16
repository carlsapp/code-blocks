#ifndef MERGESORT_H_
#define MERGESORT_H_

#include <cstring>  // For memcpy()

template<class T>
void mergeSort(T valueArray[], int arrayLen)
{
    if (arrayLen < 2) {
        return;
    }
    int midIndex = arrayLen / 2;
    // Sort the first half
    mergeSort(valueArray, midIndex);
    // Sort the second half
    mergeSort(valueArray + midIndex, arrayLen - midIndex);
    
    // And merge the two sorted halves
    // Copy our data to a temporary array. We will be putting the result into the original array.
    T *arrayCopy = new T[arrayLen];
    memcpy(arrayCopy, valueArray, arrayLen * sizeof(int));
    int firstHalfPos = 0, destPos = 0;
    int secondHalfPos = midIndex;
    while (firstHalfPos < midIndex && secondHalfPos < arrayLen) {
        if (arrayCopy[firstHalfPos] <= arrayCopy[secondHalfPos]) {
            valueArray[destPos++] = arrayCopy[firstHalfPos++];
        } else {
            valueArray[destPos++] = arrayCopy[secondHalfPos++];
        }
    }
    // Copy anything still left
    while (firstHalfPos < midIndex) {
        valueArray[destPos++] = arrayCopy[firstHalfPos++];
    }
    while (secondHalfPos < arrayLen) {
        valueArray[destPos++] = arrayCopy[secondHalfPos++];
    }
    delete[] arrayCopy;
}

#endif /* MERGESORT_H_ */
