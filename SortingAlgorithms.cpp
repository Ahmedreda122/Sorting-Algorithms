#include <iostream>
#include <algorithm>
#include <time.h>
#define ll long long
using namespace std;

namespace sort
{
  //------------------------**PRINTARR**-------------------------------------
  template <typename type, size_t size>
  void printarr(const type(&arr)[size])
  {
    cout << '{';
    for (int i = 0; i < size; i++)
    {
      if (i == size - 1)
      {
        cout << arr[i] << "}\n";
        break;
      }
      cout << arr[i] << ", ";
    }
  }

  
  //------------------------**QUICK SORT**-----------------------------------

  //  start => cursor to start of the array
  //  end => cursor to the end of the array
  template <typename type, size_t size>
  int partition(type (&arr)[size], int start, int end)
  {
    // Pick the Pivot Index Randomly
    int pivotIndex = start + rand() % ((end - start) + 1); // Random numbers in  range of : (start) to (size - 1)
    // Make the picked Pivot in the Start index
    swap(arr[pivotIndex], arr[start]);
    // Make a reference to the pivot
    int& pivot = arr[start];

    int i = start; 

    for (int j = i + 1; j <= end; ++j)
    {
      // If the element is lower than the pivot then swap it to arr[++i] and increment i;
      /*
        'i' Here is like pivot final position, 
        So We get all element lower than the pivot behind index 'i' (or on index 'i'), 
        Then in the end, We swap the pivot with arr[i] to move it to its right position.
      */ 
      if (arr[j] < pivot)
      {
        swap(arr[j], arr[++i]);
      }
    }
    // Swap the pivot to its final position
    swap(pivot, arr[i]);

    // Returing the position of pivot
    return i;
  }

  template <typename type, size_t size>
  void quickSort(type (&arr)[size], int start, int end)
  {
    // Checking that the array is not a single element
    if (start < end)
    {
      // Determine the right Pivot position
      int pivot = partition(arr, start, end);
      // Run the same process on left part that lower than the pivot.
      quickSort(arr, start, pivot - 1);
      // Run the same process on right part that higher than the pivot.
      quickSort(arr, pivot + 1, end);
    }
    // Else if the array is a single element then return
  }


  //------------------------**BUBBLE SORT**-----------------------------------
  template <typename type, size_t size>
  void bubbleSort(type (&arr)[size])
  {
    // Counter to check if the array is already sorted
    int counter = 0;
    for (int i = 0; i < size - 1; ++i)
    {
      /*
        Iteration to move element to their right place
        by swapping the higher element with the lower element that become after it.
      */ 
      for (int j = 0; j < size - i - 1; ++j)
      {
        if (arr[j] > arr[j + 1])
        {
          swap(arr[j], arr[j + 1]);
          ++counter;
        }
      }
      /*
        Checking if the array is already sorted
        by checking the number of swapping happens in the iteration
        IF NO Swap occurs in the iteration that means that the array is already sorted
      */
      if (counter == 0) 
        return;
      else
        counter = 0; // Reset the counter to check the # of swaps in the next iteration.
    }
  }

  //------------------------**COUNTING SORT**-----------------------------------
  template <typename type, size_t size>
  void countingSort(type (&arr)[size])
  {
    // Making Cumulative frequency array for Elements from 0 to max
    int Max = *max_element(arr, arr + size) + 1;
    int cFreq[Max];
    int sorted[size];

    // Filled frequencies array with zeros
    for (int i = 0; i < Max; ++i)
    {
      cFreq[i] = 0;
    }

    // Intialize frequencies of "arr" in cFreq array 
    // (Index (Element) => value (frequency))
    for (int j = 0; j < size; ++j)
    {
      // Increment frequency of arr[i] by one
      ++cFreq[arr[j]];
    }

    for (int k = 1; k < Max; ++k)
    {
      // Transfer frequency into Cumulative Frequency array
      // (Index (Element) => value (its right order in "arr" => its index = Cfreq - 1))
      cFreq[k] += cFreq[k - 1];
    }

    for (int i = 0; i < size; ++i)
    {
      // Get Cumulative Frequency (Element's Right Index - 1) of the Element arr[i] 
      // Then put the element value in the right position (its Cumulative frequncy - 1)
      sorted[cFreq[arr[i]] - 1] = arr[i];
      // Update the value of the Cumulative Frequency of the Element arr[i]
      --cFreq[arr[i]];
    }
    
    // Copy sorted array into "arr" 
    for (int i = 0; i < size; ++i)
    {
      arr[i] = sorted[i];
    }
  }


  //------------------------**SHELL SORT**-----------------------------------
  template <typename T, size_t Size>
  void shellSort(T (&Array)[Size])
  {
    for (int i = Size / 2; i > 0; i /= 2) // loop while decreasing distance between elements (gap)
    {
      for (int j = 0; j < Size; j += i) // loop within the distance between elements (gap)
      {
        // set the current element as a temporary value
        T Temp = Array[j];
        // move the elements within each gap, until the temporary value is in its correct position
        for (int z = j; z >= i && Array[z - i] > Temp; z -= i)
        {
            // if it's greater than the temporary value,
            // swap the current element with the element in the previous gap
            swap(Array[z], Array[z - i]);
        }
      }
    }
  }

  //-------------------------**MERGE SORT**--------------------------------------------------------------------
  template <typename T>
  void merge(T LeftArray[], T RightArray[], T Array[], int LeftArraySize, int RightArraySize, int ArraySize)
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
  void mergeSort(T Array[], int ArraySize)
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
      mergeSort(LeftArray, Middle);
      mergeSort(RightArray, ArraySize - Middle);
      merge(LeftArray, RightArray, Array, Middle, ArraySize - Middle, ArraySize);
  }

  //------------------------**INSERTION SORT**-----------------------------------

  template<typename T>
  void insertionSort(T arr[],ll size){
      for(int i = 1; i < size;i++){
          T key = arr[i];
          int j = i - 1;
          while(j >= 0 && key < arr[j]){
              arr[j+1] = arr[j];
              j--;
          }
          arr[j+1] = key;
      }
  }

  //------------------------**SELECTION SORT**-----------------------------------

  template<typename T>
  void selectionSort(T arr[],ll size){
      // 50 5 4 9 6 8
      for(size_t i = 0;i < size-1;i++){
          ll mn = i;
          for(size_t j = i+1; j < size;j++){
              if(arr[j] < arr[mn]){mn = j;}
          }
          swap(arr[mn], arr[i]);
      }
  }
}

