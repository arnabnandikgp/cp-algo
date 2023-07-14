#include "bits/stdc++.h"
using ll = long long;
using namespace std;
#define endl "\n"
ll n;
ll arr[100010];
int dp[10000][10000];
ll flag=0;

int rec(int l, int r) // will return the max number of digits we can get rid off between index l and r
{
  // pruning

  // base case
  if (l == r)
  {
    return 1;
  }

  // caching
  if (dp[l][r] != -1)
  {
    flag=1;
    return dp[l][r];
  }
  // computation and transition
  // int ans = -1e9;
  int ans;
  if (arr[l] == arr[r])
  {
    ans = r - l + 1;
  }
  else
  {
    ans = max(rec(l + 1, r), rec(l, r - 1));
  }
  // saving and returning
  return ans = dp[l][r];
  return ans;
}
void solve()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  memset(dp,-1,sizeof(dp));
  cout<<rec(0,n-1)<<endl;
  cout<<flag<<endl;
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll t;
  cin >> t;
  while (t--)
  {
    solve();
  }
}