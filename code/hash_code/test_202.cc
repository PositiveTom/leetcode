#include <iostream>
#include <set>

//  废了九牛二虎之力写出来的程序不值得推荐
bool IsHappyNum(int nums)
{
    std::set<std::multiset<int>> result;
    std::multiset<int> number_sets;
    int i = 0, number_sets_sum = 0;
    while( true )
    {
        number_sets.clear();
        int temp = nums;
        std::cout << "temp:" << temp << std::endl;
        if(temp < 10)
        {
            number_sets.emplace(temp);
        }
        else
        {
            while( temp/10 > 0)
            {
                if(temp % 10 != 0)
                    number_sets.emplace(temp%10);
                temp = temp / 10;
                if(temp < 10)
                    number_sets.emplace(temp);
            }
        }
        for(auto &value : number_sets)
        {
            std::cout << "value:" << value << std::endl;
        }
        if(result.count(number_sets) != 0)
        {
            break;
        }
        result.emplace(number_sets);
        number_sets_sum = 0;
        for(auto &number_set : number_sets)
        {
            number_sets_sum += number_set * number_set;
        }
        std::cout << "number_sets_sum:" << number_sets_sum << std::endl;
        nums = number_sets_sum;
        if(nums == 1)
        {
            return true;
        }
        i++;
    }
    return false;
}


class solution
{
public:
    bool IsHappy(int num)
    {
        std::set<std::multiset<int>> result;
        std::multiset<int> temp;

        while(true)
        {
            temp.clear();
            while(num)
            {
                temp.emplace(num%10);
                num/=10;
            }
            if(result.find(temp)!=result.end())
            {
                return false;
            }
            result.emplace(temp);
            int sum = 0;
            for(auto &temp_value:temp)
            {
                sum += temp_value*temp_value;
            }
            num = sum;
            if(num == 1)
            {
                return true;
            }
        }
    }



};



int main(int argc, char** argv)
{
    // std::cout << 10 / 3 << std::endl;
    std::cout << IsHappyNum(189) << std::endl;

    solution person;
    std::cout << person.IsHappy(19) << std::endl;

    return 0;
}