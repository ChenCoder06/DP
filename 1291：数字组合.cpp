#include <iostream>
#include <vector>
#include <algorithm>

//背包问题的方案总数
//每个数字只能用一次

int main()
{
    //n表示正整数的个数，t为要求的和;
    int n,t;
    std::cin >> n >> t;
    std::vector<int> Var(n+1);
    for(int i = 1;i<=n;i++)
    {
        std::cin >> Var[i];
    }
    std::vector<long long> dp(t+1,0);
    dp[0] = 1;
    for(int i = 1;i<=n;i++)
    {
        for(int j =t;j>=Var[i];j--)
        {
            dp[j] += dp[j-Var[i]];
        }
    }
    std::cout << dp[t];
    return 0;
}