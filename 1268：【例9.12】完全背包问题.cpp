#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n,m;
    std::cin >> m >> n;
    //w重量，c价值
    std::vector<int> w(n+1),c(n+1);
    for(int i = 1;i<=n;i++)
    {
        std::cin >> w[i] >> c[i];
    }
    //二维数组方式
    std::vector<std::vector<int>> arr(n+1,std::vector<int> (m+1,0));
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            if(j<w[i])
            {
                arr[i][j] = arr[i-1][j];
            }  
            else
            {
                arr[i][j] = std::max(arr[i][j-w[i]]+c[i],arr[i-1][j]);
            }
        }
    }
    //一维滚动数组方式
    // std::vector<int> brr(m+1);
    // for(int i = 1;i<=n;i++)
    // {
    //     for(int v = w[i];v<=m;v++)
    //     {
    //         brr[v] = std::max(brr[v],brr[v-w[i]]+c[i]);
    //     }
    // }
    std::cout << "max=" << arr[n][m];
    //std::cout << "max=" << brr[m];
    return 0;
}