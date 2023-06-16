
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define fr(n) for (int i = 0; i < n; i++)
#define endl "\n"
#define mp make_pair
#define ll long long

int n;
int arr[100100];
int dp[100100];

int rec(int level, int last) // will return the value of LIS from index [level...n-1]
// last is the index of the last element chosen for the LIS in range [0...level-1]
{
    // pruning
    if (level >= n)
    {
        return 0;
    }

    // base case
    if (level >= n)
    {
        return 0;
    }

    // cache check
    if (dp[level, last] != -1)
    {
        return dp[level, last];
    }

    int ans = 1;
    // compute/transition
    // taking
    if (arr[level] > arr[last])
    {
        ans = 1 + rec(level + 1, arr[level]);
    }
    // not taking

    ans = max(ans, rec(level + 1, arr[last]));

    // save and return ans
    return dp[level, last] = ans;
}

// driver code
void solve()
{
    cin >> n;
    fr(n)
    {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    cout<<rec(0,0);
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