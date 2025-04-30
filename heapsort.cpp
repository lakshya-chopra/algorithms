#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

void swap(vector<int> &arr, int idx, int right)
{

    int temp = arr[idx];
    arr[idx] = arr[right];
    arr[right] = temp;
}

// applies the max heapify at the rooted node i, assuming its left & right subtrees are already max Heaps.
void maxHeapify(vector<int> &arr, int i, size_t size)
{

    int l = 2 * i + 1; // idx starts from 0
    // cout << "l: " << l << endl;
    int r = 2 * i + 2;
    // cout << "r: " << r << endl;

    int largest = i; //by default

    if (l < size && arr[l] > arr[i])
    {
        largest = l;
    }

    if (r < size && arr[r] > arr[l])
    {

        largest = r;
    }

    if (largest != i)
    {

        swap(arr, largest, i);
        maxHeapify(arr, largest, size);
    }
}

void buildMaxHeap(vector<int> &arr, int size)
{

    for (int i = size / 2 - 1; i >= 0; i--)
    {
        cout << i << endl;

        maxHeapify(arr, i, size);
    }
}

void heapSort(vector<int> &arr)
{
    int n = arr.size();
    buildMaxHeap(arr, n);

    for (int i = n - 1; i >= 1; i--)
    {
        swap(arr, 0, i);             
        maxHeapify(arr, 0, i);        
    }

    /*
    example:

    after build max heap:
    [10, 5, 3, 4, 1]

    largest swapped to the end -> [1, 5, 3, 4, 10]

    now again call heapify: [5, 1, 3, 4, 10]

    & swap 5 with 4 to get: [4, 1, 3, 5, 10] ...

    
    */
}

void printVector(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{

    vector<int> arr;
    for (int i = 0; i < 10; i++)
    {
        arr.push_back(rand() % 201);
    }

    cout << arr[1] << endl;
    cout << arr[3] << endl;

    cout << "Original Arr"<<endl;
    printVector(arr);

    // buildMaxHeap(arr, arr.size());

    heapSort(arr);
    cout << "Sorted Arr"<<endl;
    printVector(arr);

    return 0;
}

/*

Worst: O(nlogn)

(worst = best = avg)

*/