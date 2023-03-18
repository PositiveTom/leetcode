#include <iostream>
#include <vector>

//  整数拆分
int IntegerBreak(int n)
{
    std::cout << "in" << std::endl;
    //  1. dp数组, 下标---找dp数组比较难, dp数组找不到
    //  2. 递推公式
    //  3. 初始化
    //  4. 遍历顺序
    //  5. 举例
    
    //   最大乘积--元素的乘积最大，子元素的乘积也是最大
    //   a{k} = max(a{1}+a{k-1}, ..., a{k/2}+a{k/2}) 递推公式
    //   初始化 a[1] = 1 a[2] = 2 
    //   遍历顺序 1->2->3->4
    std::vector<int> a(n+1, 0);
    a[1] = 1;

    for(int i=2; i<n+1; i++)
    {
        int max_product = 0;
        for(int j=1; j<=i/2; j++)
        {
            if(a[j]!=0)
            {
                if(a[i-j]!=0)
                {
                    if(max_product < a[j]*a[i-j])
                        max_product = a[j]*a[i-j];
                }
                else
                {
                    a[i-j] = IntegerBreak(i-j);
                    if(max_product < a[j]*a[i-j])
                        max_product = a[j]*a[i-j];
                }
            }
            else
            {
                a[j] = IntegerBreak(j);
                if(a[i-j]!=0)
                {
                    if(max_product < a[j]*a[i-j])
                        max_product = a[j]*a[i-j];
                }
                else
                {
                    a[i-j] = IntegerBreak(i-j);
                    if(max_product < a[j]*a[i-j])
                        max_product = a[j]*a[i-j];
                }
            }
            if(j == i/2)
                break;
        }
        a[i] = max_product;
        printf("a[%d]=%d \n", i, a[i]);
    }
    return a[n];
}


int NewIntegerBreak(int n)
{
    //  

}


int main(int argc, char** argv)
{
    // std::cout << IntegerBreak(3) << std::endl;

    return 0;
}