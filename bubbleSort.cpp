#include <iostream>

using namespace std;

template <typename type, size_t size>
void bubbleSort(type (&arr)[size]);

int main()
{
  // 10, 20, 25, 30, 40, 50, 60
  int arr[7] = {10, 30, 25, 20, 60, 40, 50};
  bubbleSort(arr);

  int size = sizeof(arr) / sizeof(arr[0]);
  cout << '{';
  for (int i = 0; i < size; ++i)
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