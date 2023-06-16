#include <bits/stdc++.h>
using namespace std;

int n;
int t[10010];
int s[10010];
int x, k;

int dp[101][101][101];

int rec(int level, int time_taken, int item_taken) // it will return the max skill from [level...n-1]
{

    // pruning

    // base case
    if (level == n)
    {
        return 0;
    }

    // cache check
    if (dp[level][time_taken][item_taken] != -1)
    {
        return dp[level][time_taken][item_taken];
    }

    // compute/transition
    int ans = rec(level + 1, time_taken, item_taken);

    if (time_taken + t[level] <= x && item_taken + 1 <= k)
    {
        ans = max(ans, s[level] + rec(level + 1, time_taken + t[level], item_taken + 1));
    }

    // save and return ans

    return dp[level][time_taken][item_taken] = ans;
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
        cin >> s[i];
    }
    cin >> x >> k;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0, 0) << endl;
}

int main()
{
    // fast i/o
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}