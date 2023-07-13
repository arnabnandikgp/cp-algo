#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define endl '\n'

vector<vector<int>> g;
vector<int> parent;
vector<int> color;
int n, m;
bool is_cycle = 0;
void dfs(int node, int parent)
{
    color[node] = 2;
    for (auto v : g[node])
    {
        if (v == parent[node])
        {
            continue;
        }
        if (color[v] == 1)
        { // node v is a forward edge
            dfs(v,node);
        }
        else if (color[v] == 2)
        { // node v is a back edge

            is_cycle = 1;
        }
        else if (color[v] == 3)
        { // node v is a cross edge
          // do nothing
        }
    }
    color[node] = 3;
}

signed main()
{
    cin >> n >> m;
    g.resize(n + 1);
    parent.resize(n + 1);
    color.assign(n + 1, 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 1)
        {
            dfs(i, 0);
        }
    }
    is_cycle ? cout << "YES" : cout << "NO";
    cout << endl;
}