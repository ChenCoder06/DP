#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    //arr存储数字，maxx存储最大上升子序列
    std::vector<int> arr(n+1),maxx(n+1,1);
    for(int i = 1;i<=n;i++)
    {
        std::cin >> arr[i];
    } 
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=i-1;j++)
        {
            if(arr[i]>arr[j] && maxx[j]+1>maxx[i])
            {
                maxx[i] = maxx[j]+1;
            }
        }
    }
    int k = maxx[1];
    for(int i=2;i<=n;i++)
    {
        if(maxx[i]>k)
        {
            k = maxx[i];
        }
    }
    std::cout << k << std::endl;

    return 0;
}