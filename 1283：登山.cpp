#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n+1),value(n+1,1);
    for(int i = 1;i<=n;i++)
    {
        std::cin >> arr[i];
    }
    int lmax = 1,rmax = 1;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j <= i-1;j++)
        {
            if(arr[j]>arr[i])
            {
                value[i] = std::max(value[i],value[j]+1);
            }
        }
        lmax = std::max(lmax,value[i]);
    }
    std::fill(value.begin(),value.end(),1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i - 1; j++)
        {
            if (arr[j] < arr[i])
            {
                value[i] = std::max(value[i], value[j] + 1);
            }
        }
        rmax = std::max(rmax, value[i]);
    }
    std::cout << std::max(rmax,lmax);
    return 0;
}