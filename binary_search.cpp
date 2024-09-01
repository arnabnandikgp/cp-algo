#include "bits/stdc++.h"
#define ll long long
using namespace std;
#define endl "\n"


int k;
bool check(int val)
{
    // do operations of what u need.
    // to find the lower bound k
    if (val>=k) return true;
    return false;
}
void solve()
{
    int n;
    cin >> n;
    cin >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int lo = 0;
    int hi = n - 1;

    int ans = 0; // set to some default value of our liking

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(arr[mid])) // if(check(arr[mid]))   etc...
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
    int t; // number of test cases
    while(t--)
    {
        solve();
    }
}