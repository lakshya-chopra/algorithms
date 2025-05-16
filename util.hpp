#ifndef __UTIL_HPP
#define __UTIL_HPP

#include <vector>
#include <iostream>

inline void printVector(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

#endif
