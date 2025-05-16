#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "util.hpp"

using namespace std;

// inplace changing
void merge(vector<int> &arr, int left, int mid, int right)
{

    // lengths of the L & R arrays
    int n1 = mid - left + 1; // array 1 len
    int n2 = right - mid;

    cout << "n1: " << n1 << endl;
    cout << "n2: " << n2 << endl;

    // temp vectors
    vector<int> L(n1), R(n2);

    // set values of L & R
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + i + 1]; // why + 1? because left arr includes mid.
    }

    // now change in place
    int i =0,  j = 0; //int i,j = 0: i remains unintialized
    int k = left;

    while (i < n1 && j < n2)
    {

        if (L[i] <= R[j])
        {

            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++; // first j Elem set, now move to next & compare with the L's i
        }
        k++;
    }

    while (i < n1)
    {

        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {

        arr[k] = R[j];
        j++;
        k++;
    }
}

void sort(vector<int> &arr, int left, int right)
{

    if (right > left)
    {

        // divide into 2 arrays
        int mid = left + (right - left) / 2;

        sort(arr, left, mid);
        sort(arr, mid+1, right); // mid included in left side
        merge(arr, left, mid, right);
    }
    else
    {
        return;
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

    sort(arr, 0, arr.size()-1);

    printVector(arr);

    return 0;
}

/*

worst: O(nlogn) (worst = best = avg)

*/