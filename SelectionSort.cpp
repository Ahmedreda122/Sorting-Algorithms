#include <bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T>
void selectionSort(T arr[],ll size);
int main()
{
    int arr[7] = {10, 30, 25, 20, 60, 40, 50};
    int arr2[7] = {10, 30, 25, 20, 60, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, size);
    for(int i = 0 ;i < size;i++){
        cout << arr[i] << " ";
    }
}
template<typename T>
void selectionSort(T arr[],ll size){
    // 50 5 4 9 6 8
    for(size_t i = 0;i < size-1;i++){
        ll mn = i;
        for(size_t j = i+1; j < size;j++){
            if(arr[j] < arr[mn]){mn = j;}
        }
        swap(arr[mn], arr[i]);
    }
}