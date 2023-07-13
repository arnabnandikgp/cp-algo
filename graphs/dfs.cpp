#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define endl '\n'


//
// s.#..

int n, m;
vector<string> arr;
vector<vector<int>> vis;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool valid(int x, int y)
{
    if (x < 0 || y < 0 || x > n || y > m || arr[x][y] == '#')
    {
        return 0;
    }
    return 1;
}

void dfs(int x, int y)
{
    vis[x][y] = 1;  //marking every cell it visits

    for (int i = 0; i < 4; i++) // for all neighbours of (x,y) - (nx,ny) 
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (valid(nx, ny) && !vis[nx][ny])
        {
            dfs(nx, ny);
        }
    }
}
void solve()
{
    cin >> n >> m;
    arr.resize(n);
    vis.resize(n);
    int sx, sy;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            arr[i] += c;
            if (c == 'S')
            {
                sx = i;
                sy = j;
            }
        }
    }

    dfs(sx, sy);

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '.' && vis[i][j] == 1)
                ans++;
        }
    }

    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}