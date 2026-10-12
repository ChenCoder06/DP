#include <iostream>
#include <vector>
#include <algorithm>

//01背包问题

int main()
{
    //T总时间 M多少种类
    int T,M;
    std::cin >> T >> M;
    // time采摘某株草药的时间 value这株草药的价值
    std::vector<int> time(M+1),value(M+1);
    for(int i = 1;i<=M;i++)
    {
        std::cin >> time[i] >> value[i];
    }
    //dp数组用来存储最优解
    std::vector<int> dp(T+1);
    for(int i = 1;i<=M;i++)
    {
        for(int j = T;j>=time[i];j--)
        {
            dp[j] = std::max(dp[j],dp[j-time[i]]+value[i]);
        }
    }
    std::cout << dp[T];
    return 0;
}