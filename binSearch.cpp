#include <iostream>
#include <vector>

using namespace std;

int binSearch(vector<int> &arr, int left, int right, int e){

    if (left > right){
        return -1;
    }

    int mid = (left + right )/ 2;
    int mid_elem = arr.at(mid);
    if (e == mid_elem){
        return 1;
    }
    else{

        if (e < mid_elem){
            return binSearch(arr, left, mid - 1, e);
        }
        else {
            return binSearch(arr, mid + 1, right, e);
        }
        
    }

}

int main(){

    vector <int> arr = {1,3,10, 18, 20, 100, 500};

    cout << "Searching 10: "<<binSearch(arr, 0, arr.size() - 1, 10) << endl;
    cout << "Searching 200: "<<binSearch(arr, 0, arr.size() - 1, 200) << endl;


}