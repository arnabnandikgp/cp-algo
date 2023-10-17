#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> depth;
vector<int> par;
vector<vector<int>> child;

void dfs(int nn, int pp, int dd) // the node number, the parents of this node and the depth of this node
{
    depth[nn] = dd;
    par[nn] = pp;
    for (auto v : g[nn])
    {
        if (v != par[nn])
        {
            dfs(v, nn, dd + 1);
            child[nn].push_back(v);
        }
    }
}

void solve()
{
    cin >> n;
    g.resize(n + 1);
    depth.resize(n + 1);
    par.resize(n + 1);
    child.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0, 0);
    int t_height = 1e9;
    for (int i = 1; i < n + 1; i++)
    {
        t_height = min(t_height, depth[i]);
    }
    cout << t_height << endl;
}
