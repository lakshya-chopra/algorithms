#include <iostream>
#include <stdlib.h>
#include <vector>
#include "util.hpp"

using namespace std;

void swap(vector<int> &arr, int idx, int right)
{

    int temp = arr[idx];
    arr[idx] = arr[right];
    arr[right] = temp;
}

int partition(vector<int> &arr, int left, int right)
{

    // place all the elements smaller than the pivot to its left & the larger to the right of it.

    int i = left - 1;
    int pivot = arr[right];

    for (int j = left; j < right; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
            swap(arr, j, i);
        }
    }
    swap(arr, i + 1, right); // swap the pivot with the element just after the elements <= to it.
    return i + 1;
}

int RandomizedPartition(vector<int> &arr, int left, int right)
{

    // randomized pivot to prevent the worst case scenario
    int n = rand() % (right - left) + left;
    int pivot = arr.at(n);
    cout << "Pivot: " << pivot << endl;

    swap(arr, n, right);

    return partition(arr, left, right);
}

void RandomizedQuicksort(vector<int> &arr, int left, int right)
{

    if (left < right)
    {
        int n1 = RandomizedPartition(arr, left, right);
        RandomizedQuicksort(arr, left, n1 - 1); // pivot gets placed at the correct place
        RandomizedQuicksort(arr, n1 + 1, right);
    }
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

    printVector(arr);

    RandomizedQuicksort(arr, 0, arr.size() - 1);

    printVector(arr);

    return 0;
}

/*

worst: O(n^2) when pivot = greatest or smallest
best & average = O(nlogn)

*/