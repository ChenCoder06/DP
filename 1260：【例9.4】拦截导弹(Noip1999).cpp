#include <iostream>

int main()
{
    int a[1001] = {0},b[1001] = {0},h[1001] = {0};
    int i = 1,n = 0,m = 0;
    while(std::cin >> a[i])
    {
        int maxx = 0;
        for(int j = 1;j<= i-1 ;j++)
        {
            if(a[j]>=a[i] && b[j] > maxx)
                maxx = b[j];    
        }
        b[i] = maxx + 1;
        if(b[i] > m)m = b[i];
        int x = 0;
        for(int k = 1;k<=n;k++)
        {
            if(h[k] >= a[i])
            {
                if(x==0)x = k;
                else if(h[k]<h[x])x = k;
            }
        }
        if(x == 0){n++;x=n;}
        h[x] = a[i];
        i++;
    }
    std::cout << m << std::endl << n << std::endl;
    return 0;
}