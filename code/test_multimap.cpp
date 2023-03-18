#include <iostream>
#include <map>


int main(int argc, char** argv)
{
    std::multimap<int, double> mymultimap;

    //  [1]. 添加与元素
    mymultimap.emplace(1, 1.0);
    mymultimap.emplace(2, 2.0);
    mymultimap.emplace(2, 3.0);
    mymultimap.emplace(2, 1.0);

    std::cout << mymultimap.size() << std::endl;

    //  [2]. 访问具有同一键值元素的不同方法
    //  [2.1] find():返回对应键值元素序列中指向第一个元素的迭代器, count():返回具有指定键值的元素个数
    auto key = mymultimap.find(2);
    int key_num = mymultimap.count(2);
    for(int i=0; i<key_num; i++, key++)
    {
        std::cout << "find:" << key->second << std::endl;
    }

    //  [2.2]. equal_range() 方法, 返回用pair封装的两个迭代器, 迭代器类型是multimap的元素类型
    std::pair<std::multimap<int, double>::iterator, std::multimap<int, double>::iterator> result = mymultimap.equal_range(2);
    for(;result.first != result.second; result.first++)
    {
        std::cout << "equal_range:" << result.first->second << std::endl;
    }

    //  [2.3]. lower_bound() 和 upper_bound() 方法, 第一个获取同键值序列元素中指向第一个元素的迭代器, 第二个则是指向最后一个元素的下一个位置
    std::multimap<int, double>::iterator first = mymultimap.lower_bound(2);
    std::multimap<int, double>::iterator end = mymultimap.upper_bound(2);
    for(;first != end; first++)
    {
        std::cout << "bound:" << first->second << std::endl;
    }

    return 0;
}