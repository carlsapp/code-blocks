#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include <iostream>  // For cout and endl
#include "utils.h"   // For swapArrayIndices()

#define DEBUG_PRINT_LEVEL 5

template <class T>
void quickSort(T valueArray[], unsigned int arrayLen, float pivotIndexPercent)
{
    if (arrayLen < 2) {
        // If we have 0 or 1 items, its already sorted
        return;
    }
    
    unsigned int pivotIndex = (unsigned int)((arrayLen - 1) * pivotIndexPercent);
    T pivotVal = valueArray[pivotIndex];
    
    // Everything less than or equal to the pivot value is going to get moved to
    // the left side of the array. Everything greater than the pivot will stay
    // to the right side of the array.
    
#if DEBUG_PRINT_LEVEL > 0
    std::cout << "Pivoting on index " << pivotIndex << ", value " << pivotVal << ". Array: ";
    printArray(valueArray, arrayLen);
#endif
    
    unsigned int maxIndexLessOrEqPivot = -1;
    for (unsigned int i = 0; i < arrayLen; i++) {
        if (valueArray[i] <= pivotVal) {
            // Move this element to the abovePivotIndex and move our abovePivotIndex value
            //  up so that we have all values to the right of the abovePivotIndex are greater
            //  than the pivot value.
            // If all of the first elements are <= our pivot value, we'll be swapping
            //  with ourself, which is pointless. But, the added if statement will take
            //  the same amount of time as just swapping with ourself.
            swapArrayIndices(valueArray, i, ++maxIndexLessOrEqPivot);
            if (i == pivotIndex) {
                // We just swapped our pivot. Lets not lose our pivot.
                pivotIndex = maxIndexLessOrEqPivot;
            }
        }
#if DEBUG_PRINT_LEVEL >= 10
        std::cout << "After index " << i << ", array: ";
        printArray(valueArray, arrayLen);
#endif
    }
    // Move our pivot to the bottom of our values greater than pivot
    if (pivotIndex <= maxIndexLessOrEqPivot) {
        swapArrayIndices(valueArray, pivotIndex, maxIndexLessOrEqPivot);
        pivotIndex = maxIndexLessOrEqPivot;
    } else {
        swapArrayIndices(valueArray, pivotIndex, maxIndexLessOrEqPivot + 1);
        maxIndexLessOrEqPivot = maxIndexLessOrEqPivot + 1;
    }
#if DEBUG_PRINT_LEVEL > 0
    std::cout << "maxIndexLessOrEqPivot: " << maxIndexLessOrEqPivot << std::endl;
#endif
    quickSort(valueArray, pivotIndex, pivotIndexPercent);
    quickSort(valueArray + pivotIndex + 1, arrayLen - pivotIndex - 1, pivotIndexPercent);
}

template <class T>
void quickSortEndPivot(T valueArray[], unsigned int arrayLen)
{
    if (arrayLen < 2) {
        // If we have 0 or 1 items, its already sorted
        return;
    }
    
    unsigned int pivotIndex = arrayLen - 1;
    T pivotVal = valueArray[arrayLen - 1];
    
    // Debug prints
    // std::cout << "Pivoting on index " << pivotIndex << ", value " << pivotVal << ". Array: ";
    // printArray(valueArray, arrayLen);
    
    unsigned int gePivotIndex = 0;  // First index of value greater than or equal to our pivot
    for (unsigned int i = 0; i < arrayLen - 1; i++) {
        if (valueArray[i] < pivotVal) {
            // Move this element to the gePivotIndex and move our gePivotIndex value
            //  up so that we have all values to the right of the gePivotIndex are greater
            //  than the pivot value.
            // If all of the first elements are < our pivot value, we'll be swapping
            //  with ourself, which is pointless. But, the added if statement will take
            //  the same amount of time as just swapping with ourself.
            swapArrayIndices(valueArray, i, gePivotIndex++);
        }
        
        // Debug print to see how our array is changing on each iteration:
        // printArray(valueArray, arrayLen);
    }
    swapArrayIndices(valueArray, pivotIndex, gePivotIndex);
    
    // Debug print to see how our array ended up
    // std::cout << "pivotIndex: " << pivotIndex << " gePivotIndex: " << gePivotIndex << " ";
    // printArray(valueArray, arrayLen);
    
    // An example to help understand the values we pass
    //    [ 3 6 2 7 9 8 ]  Pivot = 7, pivotIndex = 5, arrayLen = 6, gePivotIndex = 7
    //     |  a  | | b |
    // We want to sort the a and b sections of valueArray next. So ...
    //    quickSort(valueArray, 3, ...)  for a
    //    quickSort(valueArray + 4, 2, ...)  for b
    quickSortEndPivot(valueArray, gePivotIndex);
    quickSortEndPivot(valueArray + gePivotIndex + 1, arrayLen - gePivotIndex - 1);
}

template <class T>
void quickSort(T valueArray[], unsigned int arrayLen)
{
    // The default will be to choose the last item
    quickSortEndPivot(valueArray, arrayLen);
    // Most people say midpoint (0.5) is better. Check out the sorting program
    // to see the proof that midpoint is better.
    // quickSort(valueArray, arrayLen, 0.5);
}

#endif /* QUICKSORT_H_ */
