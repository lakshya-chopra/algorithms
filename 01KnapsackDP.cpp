#include <iostream>
#include <vector>

using namespace std;

struct Item {
    int weight;
    int value;
};


// returns maximum value 
int knapsack(const vector<Item> &items, int capacity, vector<vector<int>> &dp) {
    int n = items.size();

    // DP table
    dp.assign(n + 1, vector<int>(capacity + 1, 0));  // n vectors of size = capacity + 1, All set to 0.

    /*
    [ w -> [0 ... capacity]
    [0 0 0 0] -> i [1 ... items]
    [0 0 ...] 
    .
    .
    .
    [0 0 0 0]
    ]
    
    */

    // Build table dp[][] in bottom-up manner
    // 2 loops, for item & then each weight. Use the result of the recursions obtained in the next one.
    for (int i = 1; i <= n; ++i) {
        int wt = items[i - 1].weight;
        int val = items[i - 1].value;

        for (int w = 0; w <= capacity; ++w) {
            if (wt <= w)
                dp[i][w] = max(dp[i - 1][w], val + dp[i - 1][w - wt]);
            else
            // skip & consider the next one // because if wt > w -> w - wt < 0 : Not Appl
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][capacity];
}

vector<int> findSelectedItems(const vector<Item> &items, const vector<vector<int>> &dp, int capacity) {
    vector<int> selectedItems;
    int n = items.size();
    int w = capacity;

    for (int i = n; i > 0 && w > 0; --i) { // check the last item & Last Weight idx.
        if (dp[i][w] != dp[i - 1][w]) {

            /*
            If the [i-1][w] IS equal then introducing [i][w] gave 0 benefit, & so 'i' shouldn't be included.
            */

            // Item i-1 was included
            selectedItems.push_back(i - 1);
            w -= items[i - 1].weight;
        }
    }

    return selectedItems;
}

int main() {
    vector<Item> items = {
        {10, 60},
        {20, 100},
        {30, 120}
    };

    int capacity = 50;
    vector<vector<int>> dp; //vector inside vector. Each element is an integer vec.

    int maxValue = knapsack(items, capacity, dp);

    cout << "Maximum value: " << maxValue << endl;

    vector<int> selectedItems = findSelectedItems(items, dp, capacity);

    cout << "Selected item indices (0-based): ";
    for (int idx : selectedItems) {
        cout << idx << " ";
    }
    cout << endl;

    for (int idx : selectedItems) {
        cout << "Item " << idx << " - Weight: " << items[idx].weight
             << ", Value: " << items[idx].value << endl;
    }

    return 0;
}

/*

O(n*W), W: max weight

*/