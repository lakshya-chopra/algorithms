#include <iostream>
#include <vector>

using namespace std;

/* min , max */

void setMinMax(int a, int b, int &min, int &max)
{

    if (a > b)
    {
        min = b;
        max = a;
    }
    else
    {
        min = a;
        max = b;
    }
}

tuple<int, int> min_max(vector<int> &arr, int size)
{

    /*
    Process array in pairs.

    If 2 | n -> n/2 possible pairs & thus we need to make 1 extra comparison for choosing min & max
    If odd -> (n-1)/2 pairs + 1 extra, just choose that 1 extra as the min & max.

    */

    int min = 0, max = 0;

    if (size % 2 == 0)
    {

        setMinMax(arr[0], arr[1], min, max);

        for (int i = 2; i < size - 1; i++)
        {

            int local_max = 0, local_min = 0;
            setMinMax(arr[i], arr[i + 1], local_min, local_max);

            /* compare with prev pair */

            if (local_max > max)
            {
                max = local_max;
            }
            if (local_min < min)
            {
                min = local_min;
            }
        }
    }
    else
    {
        min = arr[0], max = arr[0];

        for (int i = 1; i < size - 1; i++)
        {
            setMinMax(arr[0], arr[1], min, max);

            for (int i = 2; i < size - 1; i++)
            {
                int local_max = 0, local_min = 0;
                setMinMax(arr[i], arr[i + 1], local_min, local_max);

                if (local_max > max)
                {
                    max = local_max;
                }
                if (local_min < min)
                {
                    min = local_min;
                }
            }
        }
    }

    return make_tuple(min, max);
}

int main(){

    vector<int> arr = {10,20, 30 ,15, 8, 100, 120, 100};

    auto [min, max] = min_max(arr, arr.size());

    cout << "Min: " << min <<endl;
    cout << "Max: " << max <<endl;
}

/*

takes 3 * floor(n/2) comparisons [3 per pair]
Slightly loose bound for even n, tighter for odd.

*/