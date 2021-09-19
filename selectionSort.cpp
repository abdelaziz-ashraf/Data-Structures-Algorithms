#include <bits/stdc++.h>
using namespace std;

/*
    # Time Complexity:
         -  Average Case: O(n^2)
         -  Worst Case: O(n^2)

    # Space Complexity: O(1)
*/


void selectionSort(int arr[], int sz)
{
    int min_idx;
    for(int i = 0; i < sz; i++)
    {
        min_idx = i;
        for(int y = i+1; y < sz; y++)
        {
            if(arr[min_idx] > arr[y])
                min_idx = y;
        }
        swap(arr[min_idx], arr[i]);
    }
}



void print(int arr[], int sz)
{

    for (int i = 0; i < sz; i++)
        cout << arr[i] << " ";
    cout << endl;

}


int main()
{

    int arr[] = { -60, 0, 50, 30, 10,20 };
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    cout<<"Array After Selection Sort : \n";
    print(arr, n);

    return 0;
}
