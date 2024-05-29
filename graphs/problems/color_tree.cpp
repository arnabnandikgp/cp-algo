#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define endl '\n'

// int n, m;
// vector<string> arr;
// bool vis[1000][1000];
// int dx[] = {1, 0, -1, 0};
// int dy[] = {0, 1, 0, -1};

// bool check(int x, int y)
// {
//     if (x < 0 || y < 0 || x >= n || y >= m || arr[x][y] == '#')
//         return false;
//     return true;
// }

// void dfs(int x, int y)
// {
//     vis[x][y] = 1;
//     for (int i = 0; i < 4; i++)
//     {
//         int nx = x + dx[i];
//         int ny = y + dy[i];
//         if (!vis[nx][ny] && check(nx, ny))
//         {
//             dfs(nx, ny);
//         }
//     }
// }

void solve()
{
    int n;
    cin >> n;
    vector<int> con(n+1,0);
    int m =n-1;
    while(m--)
    {
        int a,b;cin>>a>>b;
        con[a]++;
        con[b]++;
    }
    int maxi=-1e9;
    for(int i=1;i<n+1;i++)
    {
        maxi = max(maxi,con[i]);
    }
    cout<<maxi+1<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}