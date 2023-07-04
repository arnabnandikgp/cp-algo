#include <bits/stdc++.h>
// #include <iostream>
#define ll long long
using namespace std;
// #define int long long
#define mod 1000000007
#define fr(n) for (int i = 0; i < n; i++)
#define endl "\n"
#define mp make_pair
int k;
int n;
int arr[100100];
bool check(int x)
{
    int lastleft = x;
    int needed = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= lastleft)
        {
            lastleft -= arr[i];
        }
        else
        {
            needed++;
            lastleft = x - arr[i];
            if (lastleft < 0)
            {
                return 0;
                // break;
            }
            if (needed > k)
            {
                return 0;
            }
        }
    }
    if (needed > k)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void solve()
{

    int n;
    cin >> n;
    int lo = -1e9;
    int hi = 0;
    vector<int> arr(n);
    fr(n)
    {
        cin >> arr[i];
        lo = max(lo, arr[i]);
        hi += arr[i];
    }

    int ans = 0; // set to some default value of our liking

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid)) // if(check(arr[mid]==0))   etc...
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}