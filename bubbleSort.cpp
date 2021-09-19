#include <bits/stdc++.h>
using namespace std;

/*
    # Time Complexity:
         - Best Case = O(n)
         -  Average Case: O(n^2)
         -  Worst Case: O(n^2)

    # Space Complexity: O(1)
*/


void bubbleSort(int arr[], int sz)
{
    bool flag = true;
    for(int i = 0; i < sz-1; i++)
    {
        for(int y = 0; y < sz-i-1; y++)
        {
            if(arr[i] > arr[y+1])
            {
                swap(arr[i], arr[y+1]);
                flag = false;
            }

        }
        if(flag)
        {
            break;
        }
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
    bubbleSort(arr, n);
    cout<<"Array After Bubble Sort : \n";
    print(arr, n);

    return 0;
}
