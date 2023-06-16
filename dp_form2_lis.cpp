
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

int rec(int level) // will give the best LIS possible from index[0...index]
// here level is the index we are currently at
{
    // pruning case
    if (level < 0 || level >= n)
    {
        return 0;
    }

    // base case
    // no base case for this problem

    // cache check
    if (dp[level] != -1)
    {
        return dp[level];
    }
    int ans = 1;// since we will always take the last element ans=1 is always the default answer
    // compute/ transition
    for (int prev = 0; prev < level; prev++)
    {
        // condition for taking
        // we will always be taking here
        if (arr[prev] <= arr[level])
        {
            ans = max(ans, 1 + rec(prev));
        }
    }
    // save and return
    return dp[level] = ans;
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
    int best = 1;
    for (int i = 0; i < n; i++)
    {
        best = max(best, rec(i));
    }
    cout << best << endl;
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