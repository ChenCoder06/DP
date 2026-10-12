#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
//utility用来使用pair

int main()
{
    int V,N,T;
    std::cin >> V >> N >> T;
    std::vector<std::vector<std::pair<int,int>>> arr;
    arr.resize(T+1);
    for(int i = 1;i<=N;i++)
    {
        int j,weight,value;
        std::cin >> weight >> value >> j;
        arr[j].push_back({weight,value});
    }
    std::vector<int> dp(V+1,0);
    for(int i = 1;i<=T;i++)
    {
        for(int j = V;j>=0;j--)
        {
            for(int k = 0;k<(int)arr[i].size();k++)
            {
                if(j>=arr[i][k].first)
                {
                    dp[j] = std::max(dp[j],dp[j-arr[i][k].first]+arr[i][k].second);
                }
            }
        }
    }
    std::cout << dp[V];
    return 0;
}