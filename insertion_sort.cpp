#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &arr, int idx1, int idx2)
{

    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

void insertionSort(vector<int> &arr, int length)
{

    for (int j = 1; j < length; j++)
    {

        for (int i = j; i >= 1; i--)
        {

            if (arr[i] < arr[i - 1])
            {
                swap(arr, i, i - 1);
            }
        }
    }
}

void printVector(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{

    vector<int> arr = {10, 5, 8, 20, 110, 105, 500, 200, 19};
    insertionSort(arr, arr.size());
    printVector(arr);
}

/*

Best: O(n), already sorted
Avg: O(n^2)
Worst: O(n^2), Reverse

*/