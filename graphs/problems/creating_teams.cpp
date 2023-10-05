#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define endl '\n'
using ii = pair<int, int>;
#define mp make_pair
#define F first
#define S second
vector<vector<int>> g;
vector<int> col; // will store the color
vector<int> vis;
void bfs(int st)
{
    queue<int> q;
    vis[st] = 1;
    q.push(st);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto v : g[cur])
        {
            if (!vis[v])
            {
                col[v] = !col[cur];
            }
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    // cout << n << m;
    g.resize(n + 1);
    col.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            bfs(i);
        }
    }
    // for(auto v:col)
    // {
    //     cout<<v<<endl;
    // }
    int flag = 0;
    for (int node = 1; node <= n; node++)
    {
        for (auto v : g[node])
        {
            if (col[v] == col[node])
            {
                flag = 1;
                break;
            }
        }
    }
    if (!flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
}