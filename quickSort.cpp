#include <iostream>
#include <time.h>

using namespace std;

template <typename type, size_t size>
void quickSort(type (&arr)[size], int start, int end);
template <typename type, size_t size>
int partition(type (&arr)[size], int start, int end);

int main()
{
  int arr[7] = {10, 30, 25, 20, 60, 40, 50};
  int size = sizeof(arr) / sizeof(arr[0]);
  quickSort(arr, 0, size - 1);

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

template <typename type, size_t size>
void quickSort(type (&arr)[size], int start, int end)
{
  if (start >= end)   
  {
    return;
  }
  else
  {
    int pivot = partition(arr, start, end);
    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1, end);
  }
}
 
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