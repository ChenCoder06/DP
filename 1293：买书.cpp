#include <iostream>
#include <array>
#include <vector>

//背包问题的方案数
//使用array存储固定价格数

int main()
{
    std::array<int,4> value = {10,20,50,100};
    int n;
    std::cin >> n;
    std::vector<long> dp(n+1);
    dp[0] = 1;
    for(int i = 0;i<4;i++)
    {
        for(int j = value[i];j<=n;j++)
        {
            dp[j] += dp[j - value[i]];
        }
    }
    std::cout << dp[n];
    return 0;
}