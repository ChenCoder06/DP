#include <iostream>
#include <vector>
#include <algorithm>

//多重背包问题




int main()
{
    int n,m;
    std::cin >> n >> m;
    //f数组用来dp运算
    std::vector<int> f(m+1,0);
    //i是选择的种类数
    for(int i = 1;i<=n;i++)
    {
        //va价格，we价值，sum数量，end二进制数（从1开始）
        int va,we,sum;
        std::cin >> va >> we >> sum;
        for(int k =1;k<=sum;k*=2)
        {
            int weight = k*we;
            int value = k*va;
            sum-=k;
            for(int j = m;j >= value;j--)
            {
                f[j] = std::max(f[j],f[j-value]+weight);
            }
        }
        if(sum>0)
        {
            int weight = sum * we;
            int value = sum * va;
            for(int j = m;j>=value;j--)
            {
                f[j] = std::max(f[j],f[j-value]+weight);
            }
        }
        
    }
    std::cout << f[m];
    return 0;
}