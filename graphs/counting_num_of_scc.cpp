#include "bits/stdc++.h"
using namespace std;
#define endl '\n'
using ll = long long;

vector<vector<int>> g; // adjacency matrix
vector<int> vis;
vector<pair<int, int>> edge_list;

void dfs(int nn, int comp)
{
    vis[nn] = comp;
    for (auto v : g[nn])
    {
        if (!vis[v])
        {
            dfs(v, comp);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    vis.assign(n + 1, 0);
    edge_list.resize(m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        edge_list.push_back(make_pair(a, b));
    }

    int comp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            comp++;
            dfs(i, comp);
        }
    }

    vector<int> num_of_edges(comp + 1);
    for (auto v : edge_list)
    {
        num_of_edges[vis[v.first]]++;
    }

    ll sum = 0;
    ll ans = 0;
    for (int i = 0; i <= comp; i++)
    {
        ans += sum * num_of_edges[i];
        sum += num_of_edges[i];
    }

    cout << ans << endl;
}

signed main()
{
    // fast i/o
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