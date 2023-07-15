#include "bits/stdc++.h"
using ll = long long;
using namespace std;
#define endl "\n"

vector<vector<int>> g;
vector<int> vis;
vector<int> col;

ll n, m;

void dfs(int node, int co)
{
  vis[node] = 1;
  col[node] = co;
  for (auto v : g[node])
  {
    if (!vis[v])
    {
      dfs(v, co);
    }
  }
}

void solve()
{
  cin >> n >> m;
  g.resize(n + 1);
  vis.assign(n + 1, 0);
  col.assign(n + 1, 0);
  while (m--)
  {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int color = 1;
  for (int i = 1; i <= n; i++)
  {
    if (!vis[i])
    {
      dfs(i, color);
      color++;
    }
  }
  map<int, int> grps;
  for (int i = 1; i <= n; i++)
  {
    grps[col[i]]++;
  }
  ll res = 1;
  for (auto v : grps)
  {
    res *= v.second;
    // cout<<v.second<<" ";
  }
  if (grps.size() == 1)
  {
    cout << 0 << endl;
  }
  // cout<<endl;
  else
  {
    cout << res << endl;
  }
  // g.clear();
  // col.clear();
  // vis.clear();
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll t = 1;
  // cin >> t;
  while (t--)
  {
    solve();
  }
}