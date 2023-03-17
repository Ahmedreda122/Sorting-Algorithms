#include <iostream>

using namespace std;
template <typename type, size_t size>
void selectionSort(type (&arr)[size]);

// 0  1  2  3  4  5  6 
// 10 20 25 30 40 50 60
// min = 50
// i = 5, j = 6

int main()
{
  int arr[7] = {10, 30, 25, 20, 60, 40, 50};
  selectionSort(arr);

  int size = sizeof(arr) / sizeof(arr[0]);
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
void selectionSort(type (&arr)[size])
{
  int minindex = 0;
 
  for(int i = 0; i < size - 1; i++)
  {
    minindex = i;
    for (int j = i + 1; j < size; j++)
    {
      if (arr[j] < arr[minindex])
      {
        minindex = j;
      }
    }
    if (minindex != i)
      swap(arr[minindex], arr[i]);
  }
}