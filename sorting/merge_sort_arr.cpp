/*
Merge sort is a divide and conquer approach to sorting arrays.
It divides the array into two equal arrays with lengths half the size of original array.
It sorts these arrays.
And then merge these sorted arrays in O(n1+n2) time to get the original sorted array.

Merge sort requires O(n) extra space 
*/
#include<iostream>
using namespace std;

void merge(int left[], int right[], int arr[], int start, int leftSize, int rightSize) {
    int i=0, j=0, k = 0;
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[start+k] = left[i];
            i++;
            k++;
        } else {
            arr[start+k] = right[j];
            j++;
            k++;
        }
    }

    while (i < leftSize) {
        arr[start+k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[start+k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    int leftSize = mid - start + 1;
    int rightSize = end - mid;
    int left[leftSize], right[rightSize];
    int it = 0;
    for (int i=start; i<=mid; i++) {
        left[it] = arr[i];
        it++;
    }

    it = 0;
    for (int i=mid+1; i<=end; i++) {
        right[it] = arr[i];
        it++;
    }

    merge(left, right, arr, start, leftSize, rightSize);
}

int main() {
    int arr[10000];
    for (int i=0; i<10000; i++) {
        arr[i] = rand() % 1000 + 1;
    }

    int n = sizeof(arr) / sizeof(arr[0]);

// ----------------------------------//
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(arr, 0, n - 1);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Running time: " << duration.count() << " milliseconds" << std::endl;

// ----------------------------------//
    // cout<<"sorted array is: "<<endl;
    // for (int i=0; i < n; i++) {
    //     cout<<arr[i]<<" ";
    // }cout<<endl;
}
