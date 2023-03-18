#include <iostream>
#include <vector>

//  组合问题：n个数按照一定规则找出k个数的组合

std::vector<std::vector<int>> result; // 存放结果
std::vector<int> path;
//  1. 函数参数和返回值
void BackTracking(int n, int k, int startindex) // n:总共有n个数, k:k个数的组合, startindex:开始遍历的索引
{   
    //  2. 终止条件(达到指定深度就return)
    if(path.size() == k)
    {
        result.push_back(path);
        return;
    }

    //  3. for循环遍历
    //  处理节点
    //  回溯
    for(int i=startindex; i<=n+path.size()-k+1; i++) // 每个BackTracking函数的作用域内，代表树的同一层，   // 这里就是剪枝优化
    //  剩余的元素不能把树填满, 计算离填满还剩几个元素 k-path.size(), 目前还有n - i + 1 个元素   n-i+1 >= k-path.size() --> n + path.size()-k+1 >= i
    {
        path.push_back(i);
        BackTracking(n, k, i+1);
        path.pop_back();
    }
}   




int main(int argc, char** argv)
{   
    BackTracking(10, 3, 1);
    std::cout << result.size() << std::endl;

    return 0;
}