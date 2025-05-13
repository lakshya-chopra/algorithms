#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void leftRotate(vector<int> &arr, int size, int rotations){

    /* Juggling algorithm
    Num of cycles: n / gcd (d, n) = k
    */

    int gcd_ = gcd(size, rotations);

    for (int i = 0; i < gcd_; i++){

        int temp = arr.at(i);
        int j = i;
        int nextPos = 0;

        while (true){

            nextPos = (j + rotations) % size;
            // cout << nextPos << endl;
            if (nextPos == i){
                break;
            }

            arr[j] = arr[nextPos];
            j = j + rotations;
            
        }
        arr[j] = temp;
    }

}

void printVector(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){

    vector <int> arr = {10, 20, 30, 40, 50, 100};
    leftRotate(arr, arr.size(),2);


    printVector(arr);

}

/*

Naive Algo: TC: O(n*d), where d: number of rotations
Juggling: TC: O(n) -> says that left rotation by d is equivalent to k independent cycles 


* k*d mod n = 0
* => n | kd
* the smallest such k = n/gcd (n, d)

*/