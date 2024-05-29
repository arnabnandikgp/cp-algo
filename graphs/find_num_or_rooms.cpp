#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define endl '\n'

int n, m;
vector<string> arr;
bool vis[1000][1000];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool check(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m || arr[x][y] == '#')
        return false;
    return true;
}

void dfs(int x, int y)
{
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!vis[nx][ny] && check(nx, ny))
        {
            dfs(nx, ny);
        }
    }
}

void solve()
{
    cin >> n >> m;
    arr.resize(n + 1);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && check(i, j))
            {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;
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