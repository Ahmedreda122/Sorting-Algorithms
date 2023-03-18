#include <iostream>
using namespace std;

template <typename T>
void Merge(T LeftArray[], T RightArray[], T Array[], int LeftArraySize, int RightArraySize, int ArraySize);

template <typename T>
void MergeSort(T Array[], int ArraySize);

int main()
{
    char arr[] = {'4', '7', '5', '2', '5', '3', '8', '1', '6'};
    int size = sizeof(arr) / sizeof(arr[0]);
    MergeSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        if (i == (size - 1))
        {
            cout << arr[i];
            break;
        }
        cout << arr[i] << ", ";
    }
}

template <typename T>
void Merge(T LeftArray[], T RightArray[], T Array[], int LeftArraySize, int RightArraySize, int ArraySize)
{
    int LeftArrayIndex = 0, RightArrayIndex = 0, ArrayIndex = 0;
    // Check the Conditions For Merging
    while (LeftArrayIndex < LeftArraySize && RightArrayIndex < RightArraySize && ArrayIndex < ArraySize)
    {
        if (LeftArray[LeftArrayIndex] < RightArray[RightArrayIndex])
        {
            Array[ArrayIndex] = LeftArray[LeftArrayIndex++];
        }
        else
        {
            Array[ArrayIndex] = RightArray[RightArrayIndex++];
        }
        ArrayIndex++;
    }
    // Copy the remaining elements of LeftArray
    while (LeftArrayIndex < LeftArraySize && ArrayIndex < ArraySize)
    {
        Array[ArrayIndex] = LeftArray[LeftArrayIndex++];
        ArrayIndex++;
    }
    // Copy the remaining elements of RightArray
    while (RightArrayIndex < RightArraySize && ArrayIndex < ArraySize)
    {
        Array[ArrayIndex] = RightArray[RightArrayIndex++];
        ArrayIndex++;
    }
}

template <typename T>
void MergeSort(T Array[], int ArraySize)
{
    if (ArraySize <= 1) // Base Case
    {
        return;
    }

    int Middle = ArraySize / 2;
    T LeftArray[Middle];
    T RightArray[ArraySize - Middle];

    for (int i = 0; i < ArraySize; i++) // Copy Elements From (Array) to (Left/Right Array)
    {
        if (i < Middle) // Copy To Left Array
        {
            LeftArray[i] = Array[i];
        }
        else // Copy To Right Array
        {
            RightArray[i - Middle] = Array[i]; // i-Middle -> to make it start from 0
        }
    }
    MergeSort(LeftArray, Middle);
    MergeSort(RightArray, ArraySize - Middle);
    Merge(LeftArray, RightArray, Array, Middle, ArraySize - Middle, ArraySize);
}
