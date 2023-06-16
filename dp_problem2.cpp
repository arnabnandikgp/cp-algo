#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define fr(n) for (int i = 0; i < n; i++)
#define endl "\n"
#define mp make_pair
#define ll long long

int n;
int items[101];
int dp[101][1001000];
int t;

// now tha same problem can also be done using keeping track the left amount of sum that we need to achieve to make whole sum as t.
// but this method proves helpful for cases when we are queried upon in a given test case on multiple values of t.
// say we also need to print the possible sub-array if possible else print "not possible"
bool rec(int level, int left) // will give 0 or 1 on the basis of whether a subarray can be formedd in [level...n-1]
{

    // pruning case
    if (left < 0)
    {
        return 0;
    }

    // base case
    if (level == n)
    {
        if (left == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    // cache check
    if (dp[level][left] = !-1)
    {
        return dp[level][left];
    }

    // compute/transition
    // take
    if (left == 0)
    {
        return 1;
    }
    else
    {
        if (left - items[level] <= 0)
        {
            return dp[level + 1][left - items[level]];
        }
        // not take
        else
        {
            return dp[level + 1, left];
        }
    }
}
void printset(int level, int left)
{

    // base case
    if (level == n)
    {
        return;
    }

    // transition printing
    if (left == 0)
    {
        return;
    }
    else
    {
        if (left - items[level] <= 0) // taking
        {
            // return dp[level + 1][left - items[level]];
            cout << items[level] << " ";
        }
        else // not taking
        {
            // return dp[level + 1, left];
            return;
        }
    }
}

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> items[i];
    }
    int q;
    cin >> q;
    memset(dp, -1, sizeof(dp)); // instead of refreshing the dp array every time we get a new query we can use this method to reduce our time complexity from O(q*dp) to O(q+dp)
    while (q--)
    {
        cin >> t;
        // cout << rec(0, t) << endl;  // no rec(0,0) as we will be starting with t as let in first case
        if (rec(0, t))
        {
            printset(0, t);
            cout << endl;
        }
        else
        {
            cout << "not possible" << endl;
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    std::cout.tie(0);
    int test = 1;
    // ll test;
    // cin >> test;
    while (test--)
    {
        solve();
        // cout.flush() ;
    }
}