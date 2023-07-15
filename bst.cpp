#include "bits/stdc++.h"
#define ll long long
using namespace std;
#define endl "\n"

bool check(int k)
{
    // do operations of what u need.
}
void solve()
{
    int n;
    cin >> n;
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
        if (arr[mid] == 0) // if(check(arr[mid]==0))   etc...
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
}