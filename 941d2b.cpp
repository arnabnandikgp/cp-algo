#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        mp[p]++;
    }
    if (mp.size() % 2)
    {
        cout << "ALICE" << endl;
    }
    else
    {
        cout << "BOB"<<endl;
    }
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
