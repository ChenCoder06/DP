#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main()
{    
    //o,n需要的氧气和氮气
    int o,n,k;
    std::cin >> o >> n;
    std::cin >> k;
    std::vector<int> O2(k+1),N2(k+1),weight(k+1);
    for(int i=1;i<=k;i++)
    {
        std::cin >> O2[i] >> N2[i] >> weight[i];
    }
    std::vector<std::vector<int>> f(o+1,std::vector<int> (n+1,INT_MAX));
    f[0][0] = 0;
    for(int i = 1;i<=k;i++)
    {
        for(int j = o;j>=0;j--)
        {
            for(int l = n;l>=0;l--)
            {
                if (f[j][l] == INT_MAX)
                    continue;
                int t1 = j+O2[i],t2 = l + N2[i];
                if(t1>o)t1 = o;
                if(t2>n)t2 = n;
                if(f[t1][t2]>f[j][l]+weight[i])f[t1][t2] = f[j][l] + weight[i];
            }
        }
    }
    std::cout << f[o][n];
    return 0;
}