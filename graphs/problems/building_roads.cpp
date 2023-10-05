#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define endl '\n'
using ii = pair<int, int>;
#define mp make_pair
#define F first
#define S second

vector<vector<int>> g;
vector<int> group; // will store the comp no of the node
void dfs(int node, int comp)
{
    group[node] = comp;
    for (auto v : g[node])
    {
        if (group[v]==0)
        {
            dfs(v, comp);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);    //because of 1 indexing of nodes
    group.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int comp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!group[i])
        {
            comp++;
            dfs(i, comp);
        }
    }
    cout << comp - 1 << endl;
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
