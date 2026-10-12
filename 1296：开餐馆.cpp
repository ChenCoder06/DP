#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
//这道题本质是分组的背包问题，将距离小于k的放在一组内互斥选择
//然后在多个组里选择选还是不选,多个背包的01问题

int main()
{
    //测试的组数
    int count;
    std::cin >> count;
    while(count--)
    {
        //地点总数n,距离限制k
        int n,k;
        std::cin >> n >> k;
        std::vector<int> pos(n+1),value(n+1);
        std::vector<int> dp(n+1,0);
        for(int i = 1;i<=n;i++)std::cin >> pos[i];
        for (int i = 1; i <= n; i++)std::cin >> value[i];
        for(int i = 1;i<=n;i++)
        {
            dp[i] = dp[i-1];
            int j = i - 1;
            while(j>=1 && pos[i] - pos[j] <=k)j--;
            dp[i] =std::max(dp[i],value[i]+dp[j]);
        }
        std::cout << dp[n] << std::endl;
    }
    return 0;
}


//     //设置一个二维存储pair的数组，包含位置和价值信息
//     std::vector<std::vector<std::pair<int,int>>> arr;
//     //std::vector<int> pos(n+1),value(n+1);
//     //num用来记录开辟的组数
//     int Num = 1;
//     for(int i = 1;i<=n;i++)
//     {
//         //据题目要求，先输入位置
//         int pos;
//         std::cin >> pos;
//         //只要有一个地点里前面的地点距离大于k就resize新开一个行
//         if(i==1)
//         {
//             arr.resize(Num);
//             //题目要求，只能把pair的second设置为0
//             arr[Num-1].push_back({pos,0});
//         }
//         else
//         {
//             if(pos-(arr[Num-1].rbegin())->first>k)
//             {
//                 Num++;
//                 arr.resize(Num);
//                 arr[Num-1].push_back({pos,0});
//             }
//             else
//             {
//                 arr[Num-1].push_back({pos, 0});
//             }
//         }
//     }
//     //此时再次补充second
//     for(int i = 0;i<Num;i++)
//     {
//         for(int j = 0;j<(int)arr[i].size();j++)
//         {
//             std::cin >> arr[i][j].second;
//         }
//     }
//     int result  = 0;
//     for(int i = 0;i<Num;i++)
//     {
//         int maxx = INT_MIN;
//         for(int j =0;j<(int)arr[i].size();j++)
//         {
//             maxx = std::max(maxx,arr[i][j].second);
//         }
//         result+=maxx;
//     }
//     std::cout << result << std::endl;
// }