#ifndef INSERTIONSORT_H_
#define INSERTIONSORT_H_

#include <cstring>  // For memcpy()
#include "utils.h"  // For swapArrayIndices()

#define USE_OPTIMIZED_SWAP

template <class T>
void insertionSort(T valueArray[], int arrayLen)
{
    for (int i = 1; i < arrayLen; i++) {
        #ifdef USE_OPTIMIZED_SWAP
            int j = i;
            T valueToMove = valueArray[i];
            while (valueToMove < valueArray[j - 1] && j > 0) {
                j--;
            }
            memcpy(valueArray + j + 1, valueArray + j, (i - j) * sizeof(int));  // Move everything over 1
            valueArray[j] = valueToMove;
        #else
            for (int j = i; j > 0 && valueArray[j] < valueArray[j - 1]; j--) {
                swapArrayIndices(valueArray, j, j - 1);
            }
        #endif
    }
}

#endif /* INSERTIONSORT_H_ */
