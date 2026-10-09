#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int count;
    std::cin >> count;
    while(count--)
    {
        int n,lmax=1,rmax=1;
        std::cin >> n;
        std::vector<int> arr(n+1),value(n+1,1);
        for(int i = 1;i<=n;i++)
        {
            std::cin >> arr[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i-1;j++)
            {
                if(arr[j]>arr[i] && value[j]+1>value[i])
                {
                    value[i] = value[j] + 1;
                }  
            }
            lmax = std::max(value[i], lmax);
        }
        std::fill(value.begin(),value.end(),1);
        for(int i=n;i>=1;i--)
        {
            for(int j =n;j>=i+1;j--)
            {
                if(arr[j]>arr[i] && value[j]+1>value[i])
                {
                    value[i] = value[j] + 1;
                }
            }
            rmax = std::max(value[i], rmax);
        }
        std::cout << std::max(lmax,rmax) << std::endl;    
    }
    return 0;
}