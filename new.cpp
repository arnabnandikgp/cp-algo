#include "bits/stdc++.h"
#define ll long long
using namespace std;
#define endl "\n"

int INF = INT_MAX;
int frogJump(int n, vector<int> a)
{
    vector<int> dp(n, INF);
    dp[0] = 0, dp[1] = abs(a[1] - a[0]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2]));
    }
    return dp[n - 1];
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<int> input;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            input[i] = k;
        }
        frogJump(n,input);
    }
}