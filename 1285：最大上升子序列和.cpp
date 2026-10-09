#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n+1),value(n+1,1);
    for(int i=1;i<=n;i++)
    {
        std::cin >> arr[i];
        value[i] = arr[i];
    }
    for(int i = 1;i<=n;i++)
    {
        for(int j= 1;j<=i-1;j++)
        {
            if(arr[j] < arr[i] && value[j]+arr[i]>value[i])
            {
                value[i] = value[j] + arr[i];
            }
        }
    }
    int k = value[1];
    for(int i = 2;i<=n;i++)
    {
        if(value[i]>k)
        {
            k = value[i];
        }
    }
    std::cout << k;
    return 0;
}