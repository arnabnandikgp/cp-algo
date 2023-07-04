#include "bits/stdc++.h"
// #include <iostream>
using ll = long long;
using namespace std;
#define endl "\n"

void solve()
{
  ll n, q;
  cin >> n >> q;
  vector<ll> arr(n);
  for (ll i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  while (q--)
  {
    ll x;
    cin >> x;
    ll id = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    if (arr[id] == x)
    {
      cout << 0 << endl;
      continue;
    }
    ll neg = n - id;
    ll pos = id;
    if (neg % 2 == 0)
    {
      cout << "POSITIVE" << endl;
    }
    else
    {
      cout << "NEGATIVE" << endl;
    }
  }
}
signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  // int t;
  // cin >> t;
  while (t--)
  {
    solve();
  }
}