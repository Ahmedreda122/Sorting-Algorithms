#include <iostream>
#include <algorithm>
#include <time.h>

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
    int j = i + 1;

    for (int j = i + 1; j < size; ++j)
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
}

