#include <iostream>
#include <vector>

using namespace std;

//  使用最小花费爬楼梯
class Solution
{
public:
    int MinCostClimbStairs(std::vector<int>& cost)
    {
        //  dp数组, 下标
        //  递推公式
        //  初始化
        //  遍历顺序
        //  举例子

        //  
        //  f(k) + c_k = c_{k+1}
        //  f(k) + c_k = c_{k+2}

        //  c_{k} = c_{k-1} + f(k-1) = 
        //  c_{k} = c_{k-2} + f(k-2)
    }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        //  [1]. dp数组和上下标含义 、[2]. 递推公式、 [3]. 初始化、[4]. 遍历顺序、[5]. 举例
        vector<vector<int>> paths(rows);
        for(int k=0; k<rows; k++)
            paths[k].resize(cols);

        //  初始化
        int i = 0;
        for(; i<rows; i++ ) 
        {
            if( obstacleGrid[i][0] == 0 )
            {
                paths[i][0] = 1;
            }
            else
                break;
        }
        for(; i<rows; i++)
        {
            paths[i][0] = 0;
        }

        for(i=0 ; i<cols; i++ ) 
        {
            if( obstacleGrid[0][i] == 0 )
            {
                paths[0][i] = 1;
            }
            else
                break;
        }
        for(; i<cols; i++)
        {
            paths[0][i] = 0;
        }    

        for(int m=1; m<rows; m++)
        {
            for(int n=1; n<cols; n++)
            {
                // printf("obstacleGrid[%d][%d]=%d\n", m, n, obstacleGrid[m][n]);
                // printf("obstacleGrid[%d][%d]=%d\n", m-1, n, obstacleGrid[m-1][n]);
                // printf("obstacleGrid[%d][%d]=%d\n", m, n-1, obstacleGrid[m][n-1]);
                // std::cout << "----------------" << std::endl;
                if(obstacleGrid[m][n] == 1 || (obstacleGrid[m-1][n] == 1 && obstacleGrid[m][n-1] == 1))
                {
                    paths[m][n] = 0;
                }
                else if(obstacleGrid[m-1][n] == 1 && obstacleGrid[m][n-1] == 0)
                {
                    paths[m][n] = paths[m][n-1];
                }
                else if(obstacleGrid[m-1][n] == 0 && obstacleGrid[m][n-1] == 1)
                {
                    paths[m][n] =  paths[m-1][n];
                }
                else
                {
                    paths[m][n] = paths[m-1][n] + paths[m][n-1];
                }
            }
        }

        // for(int m=0; m<rows; m++)
        // {
        //     for(int n=0; n<cols; n++)
        //     {
        //         printf("paths[%d][%d]=%d\n", m, n, paths[m][n]);
        //     }
        // }

        return paths[rows-1][cols-1];
    }
};



int main(int argc, char** argv)
{
    Solution obj;
    std::vector<std::vector<int>> input = {{0,0,0},{0,1,0},{0,0,0}};

    std::cout << "output:\n" << obj.uniquePathsWithObstacles(input) << std::endl;
    return 0;
}