#ifndef UTILS_H_
#define UTILS_H_

void printArray(int arrayToPrint[], unsigned int arrayLen);
bool sortIsValid(int origArray[], int sortedArray[], unsigned int arrayLen);

template<class T>
void swapArrayIndices(T valueArray[], unsigned int index1, unsigned int index2)
{
    T temp = valueArray[index1];
    valueArray[index1] = valueArray[index2];
    valueArray[index2] = temp;
}

#endif /* UTILS_H_ */
