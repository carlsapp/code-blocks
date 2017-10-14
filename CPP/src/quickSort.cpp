#include <iostream>
#include "utils.h"

void swapIntArrayIndices(int intArray[], unsigned int index1, unsigned int index2)
{
    int temp = intArray[index1];
    intArray[index1] = intArray[index2];
    intArray[index2] = temp;
}

void quickSortInt(int intArray[], unsigned int arrayLen, float pivotIndexPercent)
{
    if (arrayLen < 2) {
        return;
    }
    
    unsigned int pivotIndex = (unsigned int)((arrayLen - 1) * pivotIndexPercent);
    int pivotVal = intArray[pivotIndex];
    
    // Debug prints
    //std::cout << "Pivoting on index " << pivotIndex << ", value " << pivotVal << ". Array: ";
    //printArray(intArray, arrayLen);
    
    unsigned int maxIndexLessOrEqPivot = -1;
    //unsigned int abovePivotIndex = 0;  // The first index with a value greater than the pivot value
    for (unsigned int i = 0; i < arrayLen; i++) {
        /*if (i == pivotIndex) {
            continue;
        }*/
        if (intArray[i] <= pivotVal) {
            // Move this element to the abovePivotIndex and move our abovePivotIndex value
            //  up so that we have all values to the right of the abovePivotIndex are greater
            //  than the pivot value.
            // If all of the first elements are <= our pivot value, we'll be swapping
            //  with ourself, which is pointless. But, the added if statement will take
            //  the same amount of time as just swapping with ourself.
            swapIntArrayIndices(intArray, i, ++maxIndexLessOrEqPivot);
            if (i == pivotIndex) {
            		// We just swapped our pivot. Lets not lose our pivot.
            		pivotIndex = maxIndexLessOrEqPivot;
            }
            //abovePivotIndex++;
        }
        //printArray(intArray, arrayLen);
    }
    // Move our pivot to the bottom of our values greater than pivot
    if (pivotIndex <= maxIndexLessOrEqPivot) {
    		swapIntArrayIndices(intArray, pivotIndex, maxIndexLessOrEqPivot);
    		pivotIndex = maxIndexLessOrEqPivot;
    } else {
    		swapIntArrayIndices(intArray, pivotIndex, maxIndexLessOrEqPivot + 1);
    		maxIndexLessOrEqPivot = maxIndexLessOrEqPivot + 1;
    }
    //std::cout << "maxIndexLessOrEqPivot: " << maxIndexLessOrEqPivot << std::endl;
    quickSortInt(intArray, pivotIndex, pivotIndexPercent);
    quickSortInt(intArray + pivotIndex + 1, arrayLen - pivotIndex - 1, pivotIndexPercent);
}

void quickSortInt(int intArray[], unsigned int arrayLen)
{
    // The default will be to choose the last item
    quickSortInt(intArray, arrayLen, 1);
    // Most people say midpoint (0.5) is better
}
