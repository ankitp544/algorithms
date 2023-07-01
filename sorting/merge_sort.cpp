/*
Merge sort is a divide and conquer approach to sorting arrays.
It divides the array into two equal arrays with lengths half the size of original array.
It sorts these arrays.
And then merge these sorted arrays in O(n1+n2) time to get the original sorted array.

Merge sort requires O(n) extra space 
*/
#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& left, vector<int>& right, vector<int>& arr, int start) {
    int i=0, j=0, k = 0;
    while (i < left.size() && j < right.size()) {
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

    while (i < left.size()) {
        arr[start+k] = left[i];
        i++;
        k++;
    }

    while (j < right.size()) {
        arr[start+k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    vector<int> left, right;
    for (int i=start; i<=mid; i++) {
        left.push_back(arr[i]);
    }

    for (int i=mid+1; i<=end; i++) {
        right.push_back(arr[i]);
    }

    merge(left, right, arr, start);
}

int main() {
    int arr[] = {10, 15, 11, 29, 20, 19, 31, 50, 75, 65, 43, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect(arr, arr + n);
    mergeSort(vect, 0, vect.size() - 1);
    cout<<"sorted array is:"<<endl;
    for (int i=0; i<vect.size(); i++) {
        cout<<vect[i]<<" ";
    }cout<<endl;
}
