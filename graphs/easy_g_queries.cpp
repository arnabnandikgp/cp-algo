#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define endl '\n'

void dfs(int node, int color, vector<vector<int>> &g, vector<int> &vis)
{
    vis[node] = color;
    for(auto v: g[node])
    {
        if(!vis[v])
        {
            dfs(v,color,g,vis);
        }
    }
}

void solve()
{
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> g(n+1);
    vector<int> vis(n+1,0);
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int color = 0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            color++;
            dfs(i,color,g,vis);
        }
    }
    vector<vector<int>> sc(n+1);
    for(int i=0;i<n+1;i++)
    {
        sc[vis[i]].push_back(i);
    }
    while(q--)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            int node;cin>>node;
            cout<<sc[vis[node]].size()<<endl; 
        }
        else{
            int x,y;
            cin>>x>>y;
            if(vis[x]==vis[y]) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }

    



}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}