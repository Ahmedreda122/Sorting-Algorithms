#include <bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T>
void insertionSort(T arr[],ll size);
int main()
{
    int arr[7] = {1560, 30, 25, 100, 60, 40, 50};
    int arr2[7] = {1560, 30, 25, 100, 60, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, size);
    for(int i = 0 ;i < size;i++){
        cout << arr[i] << " ";
    }
}
template<typename T>
void insertionSort(T arr[],ll size){
    for(int i = 1; i < size;i++){
        T key = arr[i];
        int j = i - 1;
        while(j >= 0 && key < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
