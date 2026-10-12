#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::string S,T;
    std::cin >> S >> T;
    int ls = S.length(),lt = T.length();
    std::vector<std::vector<int>> arr(ls+1,std::vector<int> (lt+1,0));
    for(int i = 1;i<=ls;i++)
    {
        for(int j = 1;j<=lt;j++)
        {
            arr[i][j] = std::max(arr[i-1][j],arr[i][j-1]);
            if(S[i-1] == T[j-1])
            {
                arr[i][j] = std::max(arr[i][j],arr[i-1][j-1]+1);
            }
        }
    }
    std::cout << arr[ls][lt];
    return 0;
}