#include <iostream>
#include "SortingAlgorithms.cpp"

using namespace std;

int main()
{
  int arr[7] = {10, 30, 25, 20, 60, 40, 50};
  int size = sizeof(arr) / sizeof(arr[0]);

  sort::quickSort(arr, 0, size - 1);
  sort::printarr(arr);
}