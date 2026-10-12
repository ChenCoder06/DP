#include <iostream>
#include <vector>
#include <algorithm>

bool cmp(const std::vector<int> &a, const std::vector<int> &b)
{
    return a[1]<b[1];
}



int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> arr(n+1,std::vector<int>(3,0));
    std::vector<int> value(n+1,1);
    for(int i = 1 ;i<=n;i++)
    {
        for(int j = 1;j<=2;j++)
        {
            std::cin >> arr[i][j];
        }
    }
    //sort函数其实是这样比较,调用比较函数然后cmp(*iterator，*iterator)
    //他把迭代器解一层传进比较函数，比较函数参数列表要和解一层后的类型对应
    std::sort(arr.begin(),arr.end(),cmp);
    // for(int i = 1;i<=n;i++)
    // {
    //     std::cout << arr[i][1] << ' ' << arr[i][2] << std::endl;
    // }
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=i-1;j++)
        {
            if(arr[i][2]>arr[j][2])
            {
                value[i] = std::max(value[i],value[j]+1);
            }
        }
    }
    int maxx = value[1];
    for(int i = 2;i<=n;i++)
    {
        maxx = std::max(maxx,value[i]);
    }
    std::cout << maxx;
    return 0;
}