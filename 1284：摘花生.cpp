#include <iostream>
#include <vector>
#include <algorithm>

//方向要么向下要么向右
int main()
{
    int count;
    std::cin >> count;
    while(count--)
    {
        int n,m;
        std::cin >> n >> m;
        std::vector<std::vector<int>> arr(n + 1, std::vector<int>(m + 1)),dp(n + 1, std::vector<int>(m + 1,0));
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                std::cin >> arr[i][j];
            }
        }
        dp[1][1] = arr[1][1];
        for(int i = 2;i<=n;i++)
        {
            dp[i][1] = dp[i-1][1] + arr[i][1];
        }
        for (int i = 2; i <= m; i++)
        {
            dp[1][i] = dp[1][i-1] + arr[1][i];
        }
        for(int i = 2;i<=n;i++)
        {
            for(int j = 2;j<=m;j++)
            {
                dp[i][j] = std::max(dp[i-1][j]+arr[i][j],dp[i][j-1]+arr[i][j]);
            }
        }
        std::cout << dp[n][m] << std::endl;
    }
    return 0;
}