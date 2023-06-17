
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define fr(n) for (int i = 0; i < n; i++)
#define endl "\n"
#define mp make_pair
#define ll long long

int n, m;
string a, b;
int dp[1000][1000];

int rec(int i, int j) // will return the size of lcs between indexes [i...n-1] and [j...m-1]
{
    // pruning

    // base case
    if (i >= n || j >= m)
    {
        return 0;
    }

    // cache and save
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    // compute and transition

    int ans = 0;
    ans = max(ans, rec(i + 1, j));
    ans = max(ans, rec(i, j + 1));
    if (a[i] == b[j])
    {
        ans = 1 + rec(i + 1, j + 1);
    }

    // save and return
    return dp[i][j] = ans;
}

// driver code
void solve()
{
    cin >> n,m;
    cin>>a>>b;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0);
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