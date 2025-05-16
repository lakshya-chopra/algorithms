#include <iostream>
#include <vector>
#include "util.hpp"

using namespace std;

vector<int> subsetSum(vector<int> &arr, int size, int sum)
{

    /* DP solution */

    vector<vector<int>> dpTable;
    dpTable.assign(size + 1, vector<int>(sum + 1, 0)); // n vectors of size = capacity + 1, All set to 0.

    // for (int j = 0; j <= sum; ++j)
    //     dpTable[0][j] = (j == 0); // dp[0][0] = 1, rest 0

    for (int i = 1; i < size + 1; ++i)
    {

        dpTable[i][0] = 1;

        for (int j = 1; j < sum + 1; ++j)
        {

            if (j < arr[i - 1])
            {
                dpTable[i][j] = dpTable[i - 1][j];
            }
            else
            {
                dpTable[i][j] = dpTable[i - 1][j] || dpTable[i - 1][j - arr[i - 1]];

                /*
                    1. Checks if the sum can be formed via this or via the previous (i-1) elements.
                */
            }
        }

        /*
            i - 1 for the arr
            but i for the dpTable, because it starts from 0 (no elements)
        */
    }

    /* return the subset */

    vector<int> subSet;

    int i = size, j = sum;

    while (i > 0 && j > 0)
    {
        if (dpTable[i][j] && !dpTable[i - 1][j]) // same condition as 01 Knapsack
        {
            subSet.push_back(arr[i - 1]);
            j -= arr[i - 1];
        }
        i--;
    }

    return subSet;
}

int main()
{

    vector<int> set = {10, 20, 8, 11, 9, 5, 15, 19};
    vector<int> subSet = subsetSum(set, set.size(), 17);
    printVector(subSet);
}