#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
//  计算两个数组的交集

std::unordered_set<int> intersection(std::multiset<int> &arr1, std::multiset<int> &arr2)
{
    std::unordered_set<int> output;

    for(auto &arr_num: arr1)
    {
        if(arr2.count(arr_num) > 0)
        {
            output.emplace(arr_num);
        }
    }
    return output;
}

int main(int argc, char** argv)
{
    std::multiset<int> arr1{1,2,2,1,3};
    std::multiset<int> arr2{2,2,3};

    std::unordered_set<int> results = intersection(arr1, arr2);
    // int 
    for(auto &result : results)
    {
        std::cout << result << std::endl;
    }

    return 0;
}