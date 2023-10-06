#include "bits/stdc++.h"
using namespace std;
#define endl '\n'
using ll = long long;

vector<vector<int>> g;
vector<int> vis;
vector<int> topo;

void dfs(int node)
{
    vis[node] = 1;
    for (auto v : g[node])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
    topo.push_back(node);
}

signed main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    vis.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b); // since it is directed
    }
    // memset(dp,-1,sizeof(dp));
    // int ans=-1e9;
    // for(int i=1;i<=n;i++)
    // {
    //     ans=max(ans,rec(i));
    // }
    // cout<<ans<<endl;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    reverse(topo.begin(),topo.end());
    for(auto v:topo)
    {
        cout<<v<<" ";
    }
}

// or we can write a neat dp code for doing the same
// int dp[100000];
// int rec(int node)// bhill give the longest possible 
// {
//     if(dp[node]!=-1)
//     {
//         return dp[node];
//     }
//     int ans=1;
//     for(auto v:g[node])
//     {
//         ans=max(ans,1+rec(v));
//     }
// }

