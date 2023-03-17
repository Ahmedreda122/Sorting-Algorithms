#include <iostream>
#include <algorithm>

using namespace std;

template <typename type, size_t size>
void countingSort(type (&arr)[size]);

int main()
{
  int arr[7] = {2, 9, 5, 5, 4, 8, 4};
  countingSort(arr);

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