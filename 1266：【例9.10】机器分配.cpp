#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void show(int n, int m, int maxx, const vector<vector<int>> &f,
          const vector<vector<int>> &value);

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> value(n + 1, vector<int>(m + 1,0)), f(n + 1, vector<int>(m + 1,0));
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            cin >> value[i][j];
        }
    }
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            int maxx = 0;
            for(int k = 0;k<=j;k++)
                maxx = max(maxx,f[i-1][j-k]+value[i][k]);
            f[i][j] = maxx;
        }
    }
    cout << f[n][m] << endl;
    show(n,m,f[n][m],f,value);
    return 0;
}

void show(int n, int m, int maxx, const vector<vector<int>> &f,
          const vector<vector<int>> &value)
{
    if(n==0)return;
    for(int k = 0;k<=m;k++)
    {
        if(maxx == f[n-1][k] + value[n][m-k])
        {
            show(n - 1, k, f[n - 1][k], f, value);
            cout << n << ' ' << m-k << endl;
            break;
        }
    }
}