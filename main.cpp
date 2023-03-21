#include <iostream>
#include <time.h> 
#include "SortingAlgorithms.cpp"

using namespace std;

template <typename type, size_t size>
void intializeArr(type (&arr)[size]);

int main()
{
  int arr1[200];
  intializeArr(arr1);
  int size1 = sizeof(arr1) / sizeof(arr1[0]);
  //time_t t = time(NULL);
 // struct tm* time = localtime(&t);
  int before1 = clock();
  //sort::countingSort(arr1);
  //sort::bubbleSort(arr1);

  // sort::shellSort(arr1);
  sort::mergeSort(arr1, size1);
  // sort::quickSort(arr1, 0, size1 - 1);
  clock_t time = clock() - before1;
  sort::printarr(arr1);
  //struct tm* time1 = localtime(&t);
  printf ("This Algorithm take (%.5lf ms).\n", ((double)time/CLOCKS_PER_SEC) * 1000);


  //int n = 5;
  string choice;
  int arr[10000];
  int size = sizeof(arr) / sizeof(arr[0]);
  int before;

  cout << "                   Welcome to Sorting Algorithms Program" << endl;
  // cout << "Please Enter the size of array: " << endl;

  // do
  // {
  //   cin >> n;
  // }
  // while (n <= 0);

  // int arr[n];


  while(true)
  {
    intializeArr(arr);
    cout << "Please Choose one of the following Sorting Algorithms to perform it:\n1-Insertion Sort\n2-Selection Sort\n3-Shell Sort\n4-Counting Sort\n5-Bubble Sort\n6-Merge Sort\n7-Quick Sort\nEnter a number from 1 to 7 or Enter 0 to Exit:\n=>";
    // Getting the input from the user
    getline(cin, choice);
    /*
      Removing the spaces from the input string to the end of it, 
      Then returning a pointer to the beginning of the removed spaces 
      Then Erasing the content from if_remove returning pointer to the end of the string 
    */ 
    choice.erase(remove_if(choice.begin(), choice.end(), ::isspace), choice.end());
    cin.ignore(0);
    before = clock();
    if (choice == "1")
    {
      sort::insertionSort(arr, size);
      clock_t time = clock() - before;
      sort::printarr(arr);
      printf ("This Algorithm take (%.8lf ms).\n", ((double)time/CLOCKS_PER_SEC) * 1000);
    }
    else if (choice == "2")
    {
      sort::selectionSort(arr, size);
      clock_t time = clock() - before;
      sort::printarr(arr);
      printf ("This Algorithm take (%.8lf ms).\n", ((double)time/CLOCKS_PER_SEC) * 1000);
    }
    else if (choice == "3")
    {
      sort::shellSort(arr);
      clock_t time = clock() - before;
      sort::printarr(arr);
      printf ("This Algorithm take (%.8lf ms).\n", ((double)time/CLOCKS_PER_SEC) * 1000);
    }
    else if (choice == "4")
    {
      sort::countingSort(arr);
      clock_t time = clock() - before;
      sort::printarr(arr);
      printf ("This Algorithm take (%.8lf ms).\n", ((double)time/CLOCKS_PER_SEC) * 1000);
    }
    else if (choice == "5")
    {
      sort::bubbleSort(arr);
      clock_t time = clock() - before;
      sort::printarr(arr);
      printf ("This Algorithm take (%.8lf ms).\n", ((double)time/CLOCKS_PER_SEC) * 1000);
    }
    else if (choice == "6")
    {
      sort::mergeSort(arr, size);
      clock_t time = clock() - before;
      sort::printarr(arr);
      printf ("This Algorithm take (%.8lf ms).\n", ((double)time/CLOCKS_PER_SEC) * 1000);
    }
    else if (choice == "7")
    {
      sort::quickSort(arr, 0, size - 1);
      clock_t time = clock() - before;
      sort::printarr(arr);
      printf ("This Algorithm take (%.8lf ms).\n", ((double)time/CLOCKS_PER_SEC) * 1000);
    }
    else if (choice == "0")
    {
      cout << "Okay, Bye.";
      return 0;
    }
    else
    {
      cout << "Wrong input, try again.";
      return 1;
    }
  }
}

template <typename type, size_t size>
void intializeArr(type (&arr)[size])
{
  for (int i = 0; i < size; ++i)
  {
    // Initialize each element in the array with a random value from 0 to 99
    arr[i] = rand() % 100;
  }
} 