#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
const int N = 100010;
int inf = 1e9;
int mod = 1e9 + 7;
vector<vector<int>> g;
vector<int> vis;
void dfs(int node, int num_comp)
{
    vis[node] = 1;
    for (auto x : g[node])
    {
        if (vis[x] == 0)
        {
            dfs(x, num_comp);
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    vis.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int num_comp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            num_comp++;
            dfs(i, num_comp);
        }
    }
    cout << num_comp - 1 << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int _t;cin>>_t;while(_t--)
    solve();
}