#include "bits/stdc++.h"
using ll = long long;
using namespace std;
#define endl "\n"

vector<vector<int>> g;
vector<int> col;
int n, m;
bool is_cycle = 0;
void dfs(int node)
{
  col[node] = 2;
  for (auto v : g[node])
  {
    if (col[v] == 1)
    {
      dfs(v);
    }
    else if (col[v] == 2)
    {
      is_cycle = 1;
      return;
    }
  }
  col[node] = 3;
}

void solve()
{
  cin >> n >> m;
  g.resize(n + 1);
  col.assign(n + 1, 1);
  while (m--)
  {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
  }
  for (int i = 1; i <= n; i++)
  {
    if (col[i] == 1)
    {
      dfs(i);
    }
  }
  if (is_cycle)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
  // g.clear();
  // col.clear();
}
signed main()
{
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