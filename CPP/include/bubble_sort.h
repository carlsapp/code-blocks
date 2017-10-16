#ifndef BUBBLESORT_H_
#define BUBBLESORT_H_

#include "utils.h"   // For swapIntArrayIndices()

// My implementation of Bubble Sort. Referenced in problem 2-2 of Introduction
// to Algorithms.
template <class T>
void bubbleSort(T valueArray[], unsigned int arrayLen)
{
    unsigned int maxUnsortedIndex = arrayLen;
    while (maxUnsortedIndex > 0) {
        unsigned int prevMax = maxUnsortedIndex;
        maxUnsortedIndex = 0;
        for (unsigned int i = 1; i < prevMax; i++) {
            // Iterate through our array, pushing the larger values to the right
            if (valueArray[i] < valueArray[i - 1]) {
                swapArrayIndices(valueArray, i, i - 1);
                maxUnsortedIndex = i;
            }
        }
        // At this point, we've pushed our greatest value all the way to the
        // right. We no longer need to check that value, so we'll use
        // maxUnsortedIndex (copied to prevMax) to tell us how far we need to
        // go on the next iteration.
    }
}

#endif /* BUBBLESORT_H_ */
