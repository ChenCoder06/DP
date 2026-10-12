#include <iostream>
#include <vector>
#include <algorithm>

//01背包问题

int main()
{
    //V是容器的容量，n是多少个物品
    int V,n;
    std::cin >> V >> n;
    //column记录每个物品的体积
    std::vector<int> column(n+1);
    for(int i = 1;i<= n;i++)
    {
        std::cin >> column[i];
    }
    //dp记录状态
    std::vector<int> dp(V+1,0);
    for(int i = 1;i<=n;i++)
    {
        for(int j = V;j>=column[i];j--)
        {
            dp[j] = std::max(dp[j],dp[j-column[i]]+column[i]);
        }
    }
    std::cout << V-dp[V];
    return 0;
}