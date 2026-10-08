#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    //w是每个地窖存在的地雷数量，f最大挖雷数量，c是挖雷路径的后节点
    std::vector<long> w(n+1),f(n+1,0),c(n+1,0);
    for(int i=1;i<=n;i++)
    {
        std::cin >> w[i];
    }
    //a数组用来判断两个点是否相连，相连才能蓄着向下挖
    std::vector<std::vector<bool>> a(n+1,std::vector<bool> (n+1,0));
    int x,y;
    do
    {
        std::cin >> x >> y;
        if(x!=0  && y!=0)
        {
            a[x][y] = true;
        }
    } while (x!=0 || y!=0);
    //最后一个地窖能挖的雷就是它本身
    f[n] = w[n];
    int l,k;
    for(int i=n-1;i>=1;i--)
    {
        l = 0,k = 0;
        for(int j=i+1;j<=n;j++)
        {
            if(a[i][j] && f[j]>l)
            {
                l = f[j];
                k = j;
            }
        }
        f[i] = l + w[i];
        c[i] = k;
    }
    k = 1;
    for(int i = 2;i<=n;i++)
    {
        if(f[i]>f[k])k = i;
    }
    int maxx = f[k];
    std::cout << k;
    k = c[k];
    while(k!=0)
    {
        std::cout << "-" << k;
        k = c[k];
    }
    std::cout << std::endl << maxx << std::endl;
    return 0;
}