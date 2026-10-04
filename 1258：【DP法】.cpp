#include <iostream>
#include <algorithm>


//数字金字塔的模型是直角三角形
//题目所求是到达最底端的最大值
//每次判断到达该层每个点的最大值是多少
//然后与自身相加
//最后遍历底层节点，寻找最大值

int main()
{
    int N;
    std::cin >> N;
    int **arr = new int*[N+1];int **brr = new int*[N+1];
    for(int i = 1;i<=N;i++)
    {
        arr[i] = new int[i+2](),brr[i] = new int[i+2]();
        for(int j=1;j<=i;j++)
        {
            std::cin >> arr[i][j];
            brr[i][j]=0;
        }
    }
    brr[1][1] = arr[1][1];
    for(int i = 2;i<=N;i++)
    {
        for(int j = 1;j <= i; j++)
        {
            brr[i][j] = std::max(brr[i-1][j-1],brr[i-1][j]) + arr[i][j];
        }
    }
    int ans = 0;
    for(int i = 1;i <= N;i++)
    {
        ans = std::max(ans,brr[N][i]);
    }
    std::cout << ans;
    for(int i = 1;i <= N ;i++)
    {
        delete[] arr[i];
        delete[] brr[i];
    }
    delete[] arr;
    delete[] brr;
    return 0;
}