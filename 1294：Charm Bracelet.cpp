#include <iostream>
#include <vector>
#include <algorithm>

// 经典0—1背包问题,有n个物品，编号为i的物品的重量为w[i]，价值为c[i]
/*现在要从这些物品中选一些物品装到一个容量为m的背包中，
使得背包内物体在总重量不超过m的前提下价值尽量大。*/

int main()
{
    //n物品，m容量
    int n,m;
    std::cin >> n >> m;
    //w数组是重量，c是价值
    std::vector<int> w(n+1),c(n+1);
    for(int i = 1;i<=n;i++)
    {
        std::cin >> w[i] >> c[i];
    }
    //创建dp数组存放状态
    std::vector<int> dp(m+1);
    for(int i = 1;i<=n;i++)
    {
        for(int j =m;j>=w[i];j--)
        {
            dp[j] = std::max(dp[j],dp[j-w[i]]+c[i]);
        }
    }
    std::cout << dp[m];
    return 0;
}