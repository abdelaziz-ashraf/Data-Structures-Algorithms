#include <bits/stdc++.h>
#define ll long long

using namespace std;

void merge_function(int arr[], int start, int mid, int end){

    //stores the starting position of both parts in temporary variables .
    int pointerPart1 = start, pointerPart2 = mid+1;

    int tempArr[end-start+1] , index = 0;

    for(int i = start; i <= end; i++){
        if(pointerPart1 > mid) // if 1st part comes to an end .
            tempArr[ index++ ] = arr[pointerPart2++];

        else if(pointerPart2 > end) // if 2nd part comes to an end .
            tempArr[ index++ ] = arr[pointerPart1++];

        //checks which part has smaller element.
        else if(arr[pointerPart1] < arr[pointerPart2])
            tempArr[index++] = arr[pointerPart1++];

        else
            tempArr[index++] = arr[pointerPart2++];
    }

    for(int i = 0; i < index; i++)
        arr[start++] = tempArr[i];

}

void merge_sort(int arr[], int start, int end){

    if(start < end){
        int mid = (start+end)/2;

        merge_sort(arr, start, mid); // sort the 1st part .
        merge_sort(arr, mid+1, end); // sort the 2nd part .

        // merge the both parts by comparing elements of both the parts.
        merge_function(arr, start, mid, end);

    }

}


int main()
{
    int arr[] = {5 , 50, 2, 1, 4, 3, 0, 1, 80, 7, 10};

    merge_sort(arr, 0, 10);

    for(auto i : arr)
        cout << i << " ";
    cout << "\n";

    return 0;
}


