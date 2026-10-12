#include <iostream>
#include <vector>
#include <algorithm>
// 题目中要求商人必须在(2N-1)个单位时间穿越出去
// N*N的方阵，走一格要花1时间，要求在2N-1的时间内通过
// 左上走右下，向下走花费N时间，算上起点，走到最右要花N时间
//重叠1时间，也就是2N-1，也就是只能走右和下，和摘花生一样

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> arr(n + 1, std::vector<int>(n + 1)), dp(n + 1, std::vector<int>(n + 1,0));
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            std::cin >> arr[i][j];
        }
    }
    dp[1][1] = arr[1][1];
    for(int i = 2;i<=n;i++)
    {
        dp[i][1] = dp[i-1][1] + arr[i][1];
        dp[1][i] = dp[1][i-1] + arr[1][i];
    }
    for(int i = 2;i<=n;i++)
    {
        for(int j = 2;j<=n;j++)
        {
            dp[i][j] = std::min(dp[i-1][j],dp[i][j-1])+arr[i][j];
        }
    }
    std::cout << dp[n][n];
    return 0;
}