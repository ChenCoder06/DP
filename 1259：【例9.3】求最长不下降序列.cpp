#include <iostream>
#include <algorithm>
//arr[i][0]表示第一个数的数值本身
//arr[i][1]表示第i个位置到n位置最长的不下降序列长度
//arr[i][2]表示从i位置开始的最长不下降序列的下一个位置，若等于0表示后面没有连接项

int main()
{
    int n;
    std::cin >> n;
    int **arr = new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i] = new int[3];
        std::cin >> arr[i][0];
        arr[i][1] = 1,arr[i][2] = -1;
        
    }
    for(int i = n-2;i>=0;i--)
    {
        int len = 0,next = -1;
        for(int j = i+1;j<n;j++)
        {
            if(arr[j][0]>=arr[i][0] && arr[j][1]>len)
            {
                len = arr[j][1];
                next = j;
            }
            if(len > 0)
            {
                arr[i][1] = len+1;
                arr[i][2]=next;
            }
        }
    }
    int k = 0;
    for(int i = 1;i < n ; i++)
    {
        if(arr[i][1] > arr[k][1])
            k = i;
    }
    std::cout << "max=" << arr[k][1] << std::endl;
    bool first = true;
    while(k!=-1)
    {
        if(!first)std::cout << ' ';
        std::cout << arr[k][0];
        first = false;
        k = arr[k][2]; 
    }
    for(int i=0;i<n;i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}