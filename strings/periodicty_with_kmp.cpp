#include <bits/stdc++.h>
using namespace std;
#define ll long long

int kmp[100005];

void prefix(string s)
{
    int n = s.size();
    kmp[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        int j = kmp[i - 1];
        while (j > 0 && s[i] != s[j])
        {
            j = kmp[j - 1];
        }
        if (s[i] == s[j])
        {
            j++;
        }
        kmp[i] = j;
    }
}

void solve()
{
    string s;
    cin >> s;
    int n=s.length();
    prefix(s);
    int p=n-kmp[n-1];
    if(!(n%p))
    {
        cout<<p<<endl;
    }
    else{
        cout<<"not periodic"<<endl;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    std::cout.tie(0);
    // int t = 1;
    ll t;
    cin >> t;
    // cout<<t;
    while (t--)
    {
        solve();
        // cout.flush() ;
    }
}