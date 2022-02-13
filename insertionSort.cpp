#include <bits/stdc++.h>
#define ll long long

using namespace std;

// Nondecreasing order
void insertion_sort(int arr[], int arrSize){

    // zero based array -> i = 1 second element
    for(int i = 1; i < arrSize; i++){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }

}

// To non-increasing order -> REPLACE arr[j] > key TO arr[j] < key

int main()
{

    int arr[] = {1, 8, 5, 0, 6 ,2, 1};
    insertion_sort(arr, 7);
    for(int i = 0; i < 7; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
