#include <iostream>
#include <time.h> 
#include "SortingAlgorithms.cpp"

using namespace std;

template <typename type, size_t size>
void intializeArr(type (&arr)[size]);

int main()
{
  int arr[200];
  intializeArr(arr);
  int size = sizeof(arr) / sizeof(arr[0]);
  //time_t t = time(NULL);
 // struct tm* time = localtime(&t);
 // int before = clock();
  //sort::countingSort(arr);
 // sort::bubbleSort(arr);

  sort::quickSort(arr, 0, size - 1);
  sort::printarr(arr);
  //clock_t time = clock() - before;
  //struct tm* time1 = localtime(&t);
  printf ("It took me (%.20lf seconds).\n", time);
}

template <typename type, size_t size>
void intializeArr(type (&arr)[size])
{
  for (int i = 0; i < size; ++i)
  {
    arr[i] = rand() % 100;
  }
} 