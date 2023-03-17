#include <iostream>

using namespace std;

template <typename type, size_t size>
void insertionSort(type (&arr)[size]);

int main()
{
  int arr[7] = {10, 30, 25, 20, 60, 40, 50};
  insertionSort(arr);

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

// 0    1    2    3  4  5  6 
// 10, 30,  [30], 20, 60, 40, 50
// i = 2
// j = 0
// current = 25
template <typename type, size_t size>
void insertionSort(type (&arr)[size])
{
  int currentIndex, j;

  for (int i = 1; i < size; i++)
  {
    current = arr[i];
    j = i - 1;

    while (current < arr[j] && j >= 0)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = current;
  }
}

