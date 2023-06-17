
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define fr(n) for (int i = 0; i < n; i++)
#define endl "\n"
#define mp make_pair
#define ll long long

int n;
int arr[10001];
int dp[1000][1000];

int rec(int l, int r) // the min cost of breaking the rod in between l and r
{
    // pruning

    // base case
    if (l + 1 == r)
    {
        return 0;
    }

    // cache and save
    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }
    // compute and transition
    int ans = 1e9;
    for (int p = l + 1; p < r; p++)
    {
        ans = min(ans, arr[r] - arr[l] + rec(l, p) + rec(p, r));
    }

    // save and return
    return dp[l][r] = ans;
}

// driver code
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    arr[0] = 0;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, n);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    std::cout.tie(0);
    // int t = 1;
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
        // cout.flush() ;
    }
}