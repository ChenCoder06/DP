#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n+1),left(n+1,1),right(n+1,1);
    for(int i = 1;i<=n;i++)
    {
        std::cin >> arr[i];
    }
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j <= i-1;j++)
        {
            if(arr[j]<arr[i])
            {
                left[i] = std::max(left[i],left[j]+1);
            }
        }
    }
    for (int i = n; i >= 1; --i)
        for (int j = n; j >= i+1; j--)
            if (arr[j] < arr[i])
                right[i] = std::max(right[i], right[j] + 1);
    int maxx = 0;
    for(int i = 1;i<=n;i++)
    {
        maxx = std::max(maxx,left[i]+right[i]);
    }
    std::cout << maxx -1;
    return 0;
}