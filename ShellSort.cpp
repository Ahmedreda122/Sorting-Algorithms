#include <iostream>
using namespace std;

template <typename T>
void ShellSort(T Array[], int Size);

int main()
{
    char arr[] = {'4', '7', '5', '2', '5', '3', '8', '1', '6'};
    int size = sizeof(arr) / sizeof(arr[0]);
    ShellSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        if (i == (size - 1))
        {
            cout << arr[i];
            break;
        }
        cout << arr[i] << ", ";
    }
}

template <typename T>
void ShellSort(T Array[], int Size)
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