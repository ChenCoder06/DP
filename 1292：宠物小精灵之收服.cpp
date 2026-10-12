#include <iostream>
#include <vector>
#include <climits>
//二维背包问题

int main()
{
    // N,M,K,分别精灵球数量、初始的体力值、野生小精灵的数量。
    int N,M,K;
    std::cin >> N >> M >> K;
    //need收服小精灵需要的球，k为对皮卡丘造成的伤害
    std::vector<int> need(K+1),des(K+1);
    for(int i = 1;i<=K;i++)
    {
        std::cin >> need[i] >> des[i];
    }
    //二维数组用来计算花费精灵球和多少体力值能捕获的精灵
    std::vector<std::vector<int>> arr(N+1,std::vector<int> (M+1,0));
    //遍历精灵的个数
    for(int i = 1;i<=K;i++)
    {
        for(int l = N;l>=need[i];l-- )
        {
            //因为体力值严格不等于0，所以不能花费M体力值，只能在M-1的上限下进行计算
            for(int j = M-1;j>=des[i];j--)
            {
                arr[l][j] = std::max(arr[l][j],arr[l-need[i]][j-des[i]]+1);
            }
        }
    }
    //该部分用来找寻花费体力的最小值，存在几种状态是最大抓取精灵数但是j花费小
    int minn = INT_MAX;
    for(int i = 1;i<=N;i++)
    {
        for(int j = 1;j<=M-1;j++)
        {
            if(arr[i][j] == arr[N][M-1])
            {
                minn = std::min(minn,j);
            }
        }
    }
    std::cout << arr[N][M-1] << ' ' << M-minn;
    return 0;
}