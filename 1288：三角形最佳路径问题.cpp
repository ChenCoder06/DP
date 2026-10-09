#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    int n;
    std::cin >> n;
    //使用arr存储直角三角形样式的二维数组
    std::vector<std::vector<int>> arr(n+1),value(n+1);
    for(int i=1;i<=n;i++)
    {
        arr[i].resize(i+2,0);
        value[i].resize(i+2,-1);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            std::cin >> arr[i][j];
        }
    }
    value[1][1] = arr[1][1];
    for(int i =2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            value[i][j] = std::max(value[i-1][j-1],value[i-1][j]) + arr[i][j];
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;i++)
    {
        ans  = std::max(value[n][i],ans);
    }
    std::cout << ans << std::endl;
    return 0;
}