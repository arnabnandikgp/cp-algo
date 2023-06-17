
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define fr(n) for (int i = 0; i < n; i++)
#define endl "\n"
#define mp make_pair
#define ll long long

int n;
int dp[1000];

bool rec(int x) // return whether the person going to play now will win or not with x number of chips remaining
{
    // pruning

    // base case
    if (x == 0)
    {
        return 0;
    }

    // cache and check
    if (dp[x] != -1)
    {
        return dp[x];
    }
    // compute/ transition
    int ans = 0;
    for (int p = 1; (1 << p) <= x; p++)
    {
        if (rec(x - p) == 0)
            ans = 1;
        break;
    }

    // return and save
    return dp[x] = ans;
}

// driver code
void solve()
{
    cin >> n;
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    cout << rec(n);
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