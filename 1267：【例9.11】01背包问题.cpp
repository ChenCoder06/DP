#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    //n物品数量，m背包容量
    int n,m;
    std::cin >> m >> n;
    std::vector<int> w(n+1),c(n+1);
    for(int i = 1;i<=n;i++)
    {
        std::cin >> w[i] >> c[i];
    }
    std::vector<std::vector<int>> dp(n+1,std::vector<int>(m+1));
    for(int i = 1;i<=n;i++)
    {
        dp[i][0] = 0;
    }
    for(int i = 1;i<=m;i++)
    {
        if(w[i]<=i)
        {    
            dp[1][i] = w[i];
        }
        else
        {
            dp[1][i] = 0;
        }
    }
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            if(w[i]<=j)
            {
                dp[i][j] = std::max(dp[i-1][j],dp[i-1][j-w[i]]+c[i]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    std::cout << dp[n][m];
    return 0;
}