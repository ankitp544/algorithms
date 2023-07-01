#include<iostream>
#include<math.h>
using namespace std;
/*
    Heap sort is in-place, but might require O(logN) recursion stack space
*/
int getParent(int i) {
    return (i-1)/2;
}

int getLeft(int i) {
    return 2*i + 1;
}

int getRight(int i) {
    return 2*i + 2;
}

void maxHeapify(int arr[], int i, int n) {
    int left = getLeft(i);
    int right = getRight(i);
    int largest;
    if (left < n && arr[left] > arr[i]) {
        largest = left;
    } else {
        largest = i;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
        maxHeapify(arr, largest, n);
    }
}

void maxHeapifyArr(int arr[], int n) {
    int maxParentIndex = ceil(n/2) - 1;
    for (int i=maxParentIndex; i>=0; i--) {
        maxHeapify(arr, i, n);
    }
}

int main() {
    int arr[] = {31, 50, 75, 19, 65, 43, 23, 10, 15, 11, 29, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"array size="<<n<<endl;
    maxHeapifyArr(arr, n);
    cout<<"after max heapify"<<endl;
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;

    int end = n - 1;
    while (end > 0) {
        swap(arr[0], arr[end]);
        end--;
        maxHeapify(arr, 0, end + 1);
    }

    cout<<"sorted array"<<endl;
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;
}
