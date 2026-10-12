#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n , m;
    std::cin >> n >> m;
    std::vector<int> face(n+1);
    for(int i = 1;i<=n;i++)
    {
        std::cin >> face[i];
    }
    std::vector<long long> f(m+1,0);
    f[0] = 1;
    for(int i = 1;i<=n;i++)
    {
        for(int j = face[i];j<=m;j++)
        {
            f[j] += f[j-face[i]];
        }
        for(int k = 1;k<=m;k++)
        {
            std::cout << f[k] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << f[m];
    return 0;
}