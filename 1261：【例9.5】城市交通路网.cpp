#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    //各个城市的连线情况，数值为距离
    int **arr = new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            std::cin >> arr[i][j];
        }
    }
    //每个城市设置到终点的距离为10000000终点设置为0
    int *final_lenth = new int[n];
    for(int i=0;i<n;i++)
    {
        final_lenth[i] = 1000000;
    }
    final_lenth[n-1] = 0;
    //后继点申请并初始化为-1
    int *pre_dest = new int[n];
    for(int i = 0;i<n;i++)
    {
        pre_dest[i] = -1;
    }
    for(int i = n-2;i>=0;i--)
    {
        for(int j = i+1;j <= n -1;j++)
        {
            if(arr[i][j]>0 && final_lenth[j]!=1000000 && final_lenth[i]>arr[i][j] + final_lenth[j])
            {
                final_lenth[i] = arr[i][j] + final_lenth[j];
                pre_dest[i] = j;
            }
        }
    }
    //直接输入最小的值
    std::cout << "minlong=" << final_lenth[0] << std::endl;
    //从x=0输出，因为arr[0]是第一个地点，后续输出地点都要+1
    int x = 0;
    while(x!=-1)
    {
        std::cout << x+1 << ' ';
        x = pre_dest[x];
    }
    delete[] pre_dest;
    delete[] final_lenth;
    for(int i=0;i<n;i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}