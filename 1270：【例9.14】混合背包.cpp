#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int m,n;
    std::cin >> m >> n;
    std::vector<int> weight(n+1),value(n+1),num(n+1),dp(m+1,0);
    for(int i = 1;i<=n;i++)
    {
        std::cin >> weight[i] >> value[i] >> num[i];
    }
    for(int i = 1;i<=n;i++)
    {
        if(num[i] == 0)
        {
            for(int j = weight[i];j<=m;j++)
            {
                dp[j]= std::max(dp[j],dp[j-weight[i]] + value[i]);
            }
        }
        else
        {
            for(int j = 1;j<=num[i];j++)
            {
                for(int k = m;k>=weight[i];k--)
                {
                    dp[k] = std::max(dp[k],dp[k-weight[i]]+value[i]);
                }
            }
        }
    }
    std::cout << dp[m];
    return 0;
}