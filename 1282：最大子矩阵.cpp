#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> arr(n+1,std::vector<int> (n+1));
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            std::cin >> arr[i][j];
        }
    }
    int ans = INT_MIN;
    for(int i = 1;i<=n;i++)
    {
        std::vector<int> sum(n + 1, 0);
        for(int j = i;j<=n;j++)
        {
            for(int k = 1;k<=n;k++)
            {
                sum[k]+=arr[j][k];
            }
            int cur = 0;
            for(int k = 1;k<=n;k++)
            {
                cur = std::max(cur+sum[k],sum[k]);
                ans = std::max(ans,cur);
            }
        }
    }
    std::cout << ans;
    return 0;
}