#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> depth;
vector<int> par;
vector<vector<int>> child;
vector<vector<int>> ancestor;
vector<int> sz; // to count the number of members in the subtree of a node
vector<int> val;

// int con;
// int ans=1e9;
int ans2 = 0;
void dfs(int nn, int pp, int dd, vector<int> &exploring1, map<int, int> &exploring2) // the node number, the parents of this node and the depth of this node
{
    depth[nn] = dd;
    par[nn] = pp;
    exploring1.push_back(nn);
    ancestor[nn] = exploring1; // for any fuks related to ancestors
    sz[nn] = 1;
    // ans=min(ans,val[nn])
    ans2 += exploring2[val[nn]];
    exploring2[val[nn]]++;
    for (auto v : g[nn])
    {
        if (v != par[nn])
        {
            dfs(v, nn, dd + 1, exploring1, exploring2);
            sz[nn] += sz[v];
            child[nn].push_back(v);
        }
    }
    exploring1.pop_back();
}

void solve()
{
    cin >> n;
    g.resize(n + 1);
    depth.resize(n + 1);
    par.resize(n + 1);
    child.resize(n + 1);
    sz.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    // take in put con
    vector<int> any1;
    map<int, int> any2;
    dfs(1, 0, 0, any1, any2);
    int t_height = 1e9;
    for (int i = 1; i < n + 1; i++)
    {
        t_height = min(t_height, depth[i]);
    }
    cout << t_height << endl;
}
